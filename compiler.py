"""
compiler.py - The Tetra Compiler (v2: FCC Lattice Edition)

Converts a surface mesh (.obj) into a .tetra volumetric file whose voxels
lie on a genuine Face-Centered Cubic (FCC) lattice -- the centers of the
Rhombic Dodecahedral cells (Claim 2: The Integer Inversion).

What changed from v1:
  v1 voxelized on a plain cubic grid and SKIPPED the parity filter
  ("Simplified: we just check if points are inside mesh"). The docs and
  patent claims describe an FCC lattice; the code now matches them.

  The parity check (ix + iy + iz) % 2 == 0 is applied to INTEGER lattice
  indices, not floats. Points with even parity form the FCC lattice; each
  such point is the center of one Rhombic Dodecahedral voxel, and space is
  tiled with no gaps. Neighbor distance is sqrt(2) lattice units, with 12
  identical neighbors per cell.

.tetra format (v2):
  line 1: "TETRA2 <resolution>"   (header; v1 files had bare resolution)
  lines : "ix iy iz"              (integer FCC lattice indices, parity 0)
"""

import numpy as np
import trimesh


def compile_to_tetra(filename, output_name="model.tetra", resolution=32,
                     scale=1.0):
    """scale: post-normalization scale factor. For rendering with the
    STU Skewer (main_stu.cpp) the object must fit inside the Root
    Tetrahedron -- the Vignette Boundary. Its insphere radius is
    1/sqrt(3) ~= 0.577, so scale=0.55 keeps the whole model inside."""
    print(f"Loading {filename}...")
    try:
        mesh = trimesh.load(filename)
    except Exception as e:
        print(f"Error: Could not load file! ({e})")
        return None

    # --- Normalize: center at mass, fit in unit sphere, apply scale ---
    mesh.vertices -= mesh.center_mass
    mesh.vertices /= np.max(np.linalg.norm(mesh.vertices, axis=1))
    mesh.vertices *= scale

    # --- 1. Build the INTEGER grid first (no float round-trip) ---
    # Integer indices ix, iy, iz in [0, resolution), mapped to world
    # coordinates in [-1, 1). Working in integers from the start means
    # the parity check is exact, never a rounding accident.
    print("Building integer lattice...")
    idx = np.arange(resolution)
    gx, gy, gz = np.meshgrid(idx, idx, idx, indexing="ij")
    indices = np.vstack((gx.ravel(), gy.ravel(), gz.ravel())).T  # (N, 3) ints

    # --- 2. THE INTEGER INVERSION (Claim 2) ---
    # Keep only even-parity sites: (ix + iy + iz) % 2 == 0.
    # These are the FCC sites = Rhombic Dodecahedron centers.
    parity_mask = (indices.sum(axis=1) % 2) == 0
    fcc_indices = indices[parity_mask]
    print(f"FCC filter: {len(indices)} cubic sites -> {len(fcc_indices)} lattice sites "
          f"(ratio {len(indices)/len(fcc_indices):.2f}:1)")

    # --- 3. Map integer sites to world space and test containment ---
    spacing = 2.0 / resolution
    world = (fcc_indices + 0.5) * spacing - 1.0  # cell centers in [-1, 1)

    print("Testing mesh containment...")
    inside = mesh.contains(world)
    solid = fcc_indices[inside]
    print(f"Found {len(solid)} solid RD voxels.")

    # --- 4. Save ---
    print(f"Saving to {output_name}...")
    with open(output_name, "w") as f:
        f.write(f"TETRA2 {resolution}\n")
        for ix, iy, iz in solid:
            f.write(f"{ix} {iy} {iz}\n")

    print("Done! Compilation complete.")
    return solid


if __name__ == "__main__":
    compile_to_tetra("bunny.obj")
