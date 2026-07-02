// VoxelGrid.h - The Memory Block (v2: FCC-enforcing)
//
// v1 contained isValidLatticePoint() but never called it: the grid happily
// stored any cubic site, so the "Rhombic Dodecahedral lattice" existed only
// in the comments. v2 makes the lattice a rule, not a suggestion:
//
//   * setVoxel() silently rejects odd-parity sites. Data in the grid is
//     FCC by construction.
//   * The 12 neighbor directions of the RD cell are defined as a table
//     (the <1,1,0> permutation family), implementing "The Hopper" from
//     the System Architecture doc: movement = graph traversal, collision
//     = O(1) neighbor lookup.
//
// Storage note: we still allocate the full cubic array and leave odd-parity
// slots empty. That wastes 2x memory for the sake of a trivial O(1) index
// function -- an honest tradeoff for a prototype. A production version
// would pack even-parity sites contiguously (exactly the 2:1 integer
// volume ratio the docs describe).

#ifndef VOXELGRID_H
#define VOXELGRID_H

#include <vector>

class VoxelGrid {
public:
    int size;
    std::vector<bool> data;

    // THE 12 NEIGHBORS (The Hopper)
    // FCC coordination: all permutations of (+-1, +-1, 0).
    // Hopping any direction preserves parity: (+-1) + (+-1) + 0 is even,
    // so the lattice is closed under traversal -- you can never hop off it.
    static constexpr int NEIGHBORS[12][3] = {
        { 1, 1, 0}, { 1,-1, 0}, {-1, 1, 0}, {-1,-1, 0},
        { 1, 0, 1}, { 1, 0,-1}, {-1, 0, 1}, {-1, 0,-1},
        { 0, 1, 1}, { 0, 1,-1}, { 0,-1, 1}, { 0,-1,-1}
    };

    VoxelGrid(int s) : size(s) {
        data.resize((size_t)size * size * size, false);
    }

    int getIndex(int x, int y, int z) const {
        return x + (y * size) + (z * size * size);
    }

    // THE INTEGER INVERSION (Claim 2) -- now actually enforced.
    static bool isValidLatticePoint(int x, int y, int z) {
        // C++ % can be negative for negative operands; mask handles both.
        return ((x + y + z) & 1) == 0;
    }

    bool inBounds(int x, int y, int z) const {
        return x >= 0 && x < size && y >= 0 && y < size && z >= 0 && z < size;
    }

    // The Setter: only FCC sites may be lit.
    // Returns false if the site is off-lattice or out of bounds.
    bool setVoxel(int x, int y, int z, bool value) {
        if (!inBounds(x, y, z) || !isValidLatticePoint(x, y, z)) {
            return false;
        }
        data[getIndex(x, y, z)] = value;
        return true;
    }

    bool isSolid(int x, int y, int z) const {
        if (!inBounds(x, y, z)) return false;
        return data[getIndex(x, y, z)];
    }

    // The Hopper: query neighbor d (0..11) of cell (x,y,z).
    bool neighborSolid(int x, int y, int z, int d) const {
        return isSolid(x + NEIGHBORS[d][0],
                       y + NEIGHBORS[d][1],
                       z + NEIGHBORS[d][2]);
    }

    // Isotropic connectivity count (0..12). A cell with 12 is interior;
    // fewer means it sits on the surface of the solid.
    int solidNeighborCount(int x, int y, int z) const {
        int n = 0;
        for (int d = 0; d < 12; d++) {
            if (neighborSolid(x, y, z, d)) n++;
        }
        return n;
    }
};

#endif
