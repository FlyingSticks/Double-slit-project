# DOUBLE-SLIT GEOMETRY
### Definitions, Axioms, and Theorems for the Geometry of Cross-Slit Projection

*Companion to the Tetra Engine project. All numbered theorems verified numerically against the working codebase (verification script: `geometry_checks.py`).*

---

## 0. Orientation

A geometry, in the sense this document uses, is one object seen under two descriptions. In the synthetic tradition (Euclid, Hilbert) it is a set of primitives, a list of axioms about their incidence, and the theorems those axioms force. In the transformational tradition — the Erlangen program of Felix Klein — it is a space together with a group of transformations, and its theorems are the statements invariant under that group. The two are not rivals: they describe the same plane, and this document earns that identification in both directions — the axioms force the classical model (Theorem 2), and every automorphism of that model is induced by the group (Theorem 5.4). One tradition asks what must be true; the other asks what is preserved; they meet in the middle.

What neither tradition owns is the ladder. A geometry comes in levels, and the two descriptions merely climb it by opposite means — the synthetic one by adding axiom groups, the transformational one by shrinking the group — each rung nominating a little more structure and surrendering a little more symmetry in exchange. Projective geometry holds only incidence and the cross-ratio; affine geometry nominates the plane at infinity and gains parallelism and ratio; metric geometry nominates the absolute — the conic against which Cayley and Klein read distance and angle as cross-ratios — and gains shape, angle and length-ratio, though only up to a global scale; Euclidean geometry nominates the one quantity still missing, absolute scale, and gains length itself. The descent crosses a threshold at the metric rung: above it a geometry describes; from it downward a geometry measures.

Double-slit geometry takes its place in this family: it is what remains invariant when the only structure held sacred is a pair of skew lines — the two slits. It climbs the same ladder (§7). Its projective floor is the bare slit pair; nominating the plane at infinity yields the affine (S, T, U) chart; and nominating the screen supplies the absolute — the two feet and the screen point, three canonical points on every ray — at which the aspect ratio a round target casts becomes a cross-ratio against them (Theorem 7), and depth, the one coordinate the image alone can never fix (Theorem 5.3), becomes a measured number. That last floor is the geometry of the codec, and it takes a borrowed name, *calibrated*, for the reason set out under provenance below.

The guiding fact, stated once here and proved below: a pinhole is a point through which all rays concur; a double slit is the exact refusal of that concurrence. No two generic rays of the system meet anywhere. The geometry below is the systematic study of that refusal.

**Honesty about provenance.** The underlying objects are classical. The family of transversals to two skew lines is the hyperbolic linear congruence, studied since Plücker, Kummer, and Sturm in the nineteenth century; the camera model appears in modern imaging literature as the crossed-slits (X-slit) projection (Zomet, Feldman, Peleg, Weinshall, 2003) and as a class within the General Linear Camera taxonomy (Yu & McMillan, 2004); and the abstract axiomatics below is an instance of the theory of chain geometries and Minkowski planes developed by the school of Walter Benz (from ~1973). The name of §7's third level is borrowed in the same spirit: its classical names are *metric* and *Euclidean*, but I call it *calibrated*, after the reconstruction hierarchy of computer vision — projective → affine → metric → Euclidean — in which a camera is *calibrated* once its intrinsic matrix K is known, the very step that lifts a reconstruction to the metric level, since to know K is to know the image of the absolute conic. Of that rung's several names, only *calibrated* names the act by which a description becomes an instrument. What this document contributes is the assembly: the Erlangen-style presentation of the camera as a geometry, and Theorem 6, which identifies the Tetra Codec's working formula as a cross-ratio. I derived Theorem 6 directly and have not searched for it in the literature; it is elementary enough that it may exist somewhere, but I have not seen the codec read this way.

---

## 1. The Model

Work in real projective 3-space ℙ³. (Projective, so that "parallel" is not an exception but a location; the affine and metric layers are recovered in §7 by nominating special elements.)

Fix two skew lines ℓ₁ and ℓ₂, the **slits**. In the Tetra Engine's calibrated rig, ℓ₁ is the vertical slit in the plane z = Zv and ℓ₂ the horizontal slit in the plane z = Zh; in the Tetra coordinate system, ℓ₁ and ℓ₂ are one pair of opposite edges of the root tetrahedron. Nothing below depends on the metric placement; only skewness is used.

A **ray** is a line meeting both slits — a transversal of the pair. The set of all rays is the congruence ℛ(ℓ₁, ℓ₂). The union ℓ₁ ∪ ℓ₂ is the **seam**: the locus that belongs to every ray's addressing but to no ray's interior in the fibration of Theorem 1.

---

## 2. Primitives and Definitions

**D1 (Foot).** A ray r meets ℓ₁ in exactly one point, its first foot s(r), and ℓ₂ in exactly one point, its second foot t(r). The pair (s, t) is the **address** of the ray. (This is the (S, T) of the Tetra DSL.)

**D2 (Pencils).** Two rays are **1-parallel**, written r ∥₁ r′, if they share the first foot; **2-parallel** (∥₂) if they share the second. The ∥₁-class of all rays through a fixed point p ∈ ℓ₁ is the **S-pencil** at p; likewise **T-pencils** on ℓ₂. Each S-pencil is a flat pencil of lines: it fills the plane spanned by p and ℓ₂. So the S-pencils correspond simultaneously to the points of ℓ₁ and to the planes through ℓ₂ — each slit is read through the other. This is the **seam duality**.

**D3 (Ray space).** The set R of all rays, with its two partitions into S-pencils and T-pencils. The address map r ↦ (s(r), t(r)) identifies R with ℓ₁ × ℓ₂ ≅ ℙ¹ × ℙ¹. Contrast the pinhole: rays through a point form a ℙ². The double slit's ray space is not a projective plane; it is a product of two projective lines — a grid of two interleaved ℙ¹'s. (Equivalently: inside the Klein quadric of all lines of ℙ³, the congruence is a smooth quadric surface — itself doubly ruled. The ray space of the doubly-ruled camera is a doubly-ruled surface.)

**D4 (Chain).** A **chain** is the set of rays meeting a fixed line m that is skew to both slits. Theorem 3 shows a chain is the graph {(s, φ(s))} of a projective transformation (Möbius map) φ : ℓ₁ → ℓ₂, and identifies which lines give which chains.

**D5 (Screen and image).** A **screen** is a plane Π containing neither slit. Each ray meets Π once (away from degeneracies), so Π is a chart of the ray space: image formation is the map

> point P ⟼ its ray ⟼ that ray's address (s, t),

i.e. the image is the ray space itself, read in a chart. On the screen, the S-pencils cut out a pencil of lines through q₂ = ℓ₂ ∩ Π and the T-pencils a pencil through q₁ = ℓ₁ ∩ Π. In the Tetra rig the slits are parallel to the sensor, so q₁, q₂ lie at infinity in perpendicular directions and the two pencils become the vertical and horizontal coordinate grid: screen x is s, screen y is t.

**D6 (Depth coordinate).** On a single ray r, the four canonical points are its feet F₁ = r ∩ ℓ₁, F₂ = r ∩ ℓ₂, its screen point S = r ∩ Π, and the object point P. The depth coordinate of P is defined projectively in Theorem 6. (This is the U of the Tetra DSL.)

Throughout, cross-ratio uses the convention (A, B; C, D) = ((C−A)(D−B)) / ((C−B)(D−A)) in any affine coordinate on the line.

---

## 3. Axioms, Group I: the Camera (rays in space)

*Primitives: Points, Rays, incidence, and the seam ℓ₁ ∪ ℓ₂.*

**Axiom C1 (Threading).** Every point not on the seam lies on exactly one ray.

**Axiom C2 (Non-concurrence).** Two distinct rays have a common point if and only if they are 1-parallel or 2-parallel; the common point is then the shared foot, on the seam.

**Axiom C3 (Pencil flatness).** The rays of one pencil lie in a common plane and pass through a common seam point; every plane through one slit arises this way from a point of the other.

C1 makes space (minus the seam) a fiber bundle over the ray space: every point has a unique address (s, t) plus a position u along its ray — the (S, T, U) chart, with the seam as the singular locus. (Blowing up the two slits resolves the singularity: the blown-up ℙ³ fibers honestly over ℙ¹ × ℙ¹ with fiber ℙ¹.) C2 is the pinhole's negation made law: in a bundle of rays through a point, every two rays meet; here two rays meet only by sharing a foot, and the meeting is exiled to the seam. C1 and C2 are equivalent for the concrete model (each implies the other given C3), but both are stated because they carry the two halves of the intuition: threading is what the camera does, non-concurrence is what it refuses.

**Theorem 1 (Threading Theorem).** In the concrete model, C1–C3 hold.

*Proof.* Let P ∉ ℓ₁ ∪ ℓ₂. The planes π₁ = span(P, ℓ₁) and π₂ = span(P, ℓ₂) are distinct (else ℓ₁, ℓ₂ would be coplanar, hence not skew). Two distinct planes of ℙ³ meet in a line; π₁ ∩ π₂ passes through P, and, lying in π₁ with ℓ₁, meets ℓ₁ (two lines in a projective plane always meet); likewise ℓ₂. So a transversal through P exists. Any transversal through P lies in both planes, hence equals π₁ ∩ π₂: uniqueness. For C2: if two rays met off the seam, the meeting point would violate uniqueness; if they meet on ℓ₁, the meeting point is a common foot. Conversely 1-parallel rays meet at their shared foot. C3 is D2. ∎

---

## 4. Axioms, Group II: the Image (the geometry of ray space)

Here the rays themselves become the points of an abstract plane geometry, with pencils and chains as its structure — the geometry a decoder inhabits, which sees addresses and nothing else. *Primitives: a set R ("rays"), two equivalence relations ∥₁, ∥₂, and a family 𝒦 of subsets ("chains").*

**Axiom M0 (Grid).** Every ∥₁-class meets every ∥₂-class in exactly one ray. (Existence and uniqueness of the address.)

**Axiom M1 (Three-Ray Axiom).** Any three pairwise non-parallel rays lie on exactly one common chain.

**Axiom M2 (Touching Axiom).** If K is a chain, r ∈ K, and q ∉ K is not parallel to r, there is exactly one chain through q meeting K precisely in r.

**Axiom M3 (Richness).** Each chain meets each parallel class exactly once; there exist four pairwise non-parallel rays not on a common chain.

**Axiom M4 (Miquel Closure).** The Miquel configuration closes: given eight rays arranged as the vertices of a combinatorial cube whose five faces are concyclic quadruples (each lying on a chain), the sixth face also lies on a chain.

Axioms M0–M3 are the axioms of a **Minkowski plane** in the sense of Benz — the split-signature sibling of the Möbius (inversive) plane. M4 is the closure condition that, by the representation theorems of the Benz school (Benz; Chen), forces the classical model:

**Theorem 2 (Representation).** A Minkowski plane satisfying M4 is isomorphic to the chain geometry of the projective line over the ring K × K for a field K; in the real, connected case, to ℙ¹(ℝ) × ℙ¹(ℝ) with chains the graphs of Möbius transformations — that is, to the ray space of a double-slit camera. (Classical; see Benz, "Vorlesungen über Geometrie der Algebren," and the literature on Miquelian Minkowski planes.)

The algebraic reading deserves its own sentence. The pinhole's image geometry is coordinatized by a projective plane over ℝ; the Möbius geometry of inversive distance is the projective line over ℂ. The double slit's image geometry is the projective line over the ring ℝ ⊕ ℝ — the split-complex or double numbers: pairs (a, b) added and multiplied componentwise. Its zero-divisors are the two axes {(a, 0)} and {(0, b)} — algebraically, the seam. The number system of double-slit geometry is literally two copies of the real line glued along their arithmetic, with the gluing locus doing the work. In the Benz trinity of circle geometries — ℂ (Möbius), dual numbers (Laguerre), double numbers (Minkowski) — the double slit is the split member.

**Theorem 3 (Bowing Theorem).** In the concrete model, the image of a line m of ℙ³ is:

1. a **chain** — the graph of a Möbius map t = φ(s) — if m is skew to both slits; in the calibrated screen chart this is a curve y = (ax + b)/(cx + d), a hyperbola with asymptotes parallel to the coordinate grid: straight edges bow into conics (demos 20, 21);
2. **straight** exactly when c = 0 in that chart — the lines whose chain passes through the corner ray of the chart (in the rig: lines meeting the common transversal at screen infinity), plus the pencil lines themselves;
3. a **cross** — one full S-pencil together with one full T-pencil — if m meets a slit; in particular the image of a ray r = (s₀, t₀) is the pair of pencils {s = s₀} ∪ {t = t₀} through its feet.

*Proof sketch.* Fix a point p₂ ∈ ℓ₂. The rays with that second foot form the flat pencil in span(p₂, ℓ₁) (D2); a generic line m meets that plane once, so exactly one ray of the pencil meets m. Hence the image of m meets every T-pencil once, and symmetrically every S-pencil once: it is a bidegree-(1, 1) curve in ℙ¹ × ℙ¹, i.e. either a Möbius graph or a degenerate union of one ruling of each kind. If m meets ℓ₁ at the point with parameter s₀, every ray of the S-pencil {s = s₀} meets m (at that very point), so the image contains the whole ruling and the residual class forces a T-pencil: case 3. Otherwise the graph is nondegenerate: case 1. Case 2 is the statement that a Möbius function is affine iff its pole is at infinity. ∎ *(Verified numerically: a random line's image fits a Möbius graph to 2×10⁻¹².)*

**Theorem 4 (Regulus Ambiguity).** Two lines of ℙ³, both skew to the slits, have the same image if and only if they belong to a common regulus — one ruling of a quadric surface that contains both slits in its other ruling. Consequently the image of a line determines not the line but a one-parameter family of lines, and the chains of the geometry correspond bijectively to the quadrics through the slit pair.

*Proof sketch.* Three pairwise skew lines lie on a unique doubly-ruled quadric. Given a chain K, pick three of its rays r₁, r₂, r₃: pairwise non-parallel, hence (C2) pairwise skew; let Q be their quadric. The slits meet all three rays, so ℓ₁, ℓ₂ lie in the opposite ruling of Q. A line m has image K iff m meets every ray of K; the lines meeting all of r₁, r₂, r₃ are exactly the opposite ruling of Q. So the lines with image K form that ruling — a regulus containing both slits. Conversely lines of one ruling all meet every line of the other. ∎

Note what Theorem 4 does to the Three-Ray Axiom: M1, transported to the concrete model, is the fundamental theorem of projective geometry on ℙ¹ (a homography is determined by three points) wearing the mask of the classical fact that three skew lines determine a quadric. The axiom system knows classical line geometry without being told.

---

## 5. The Group and Its Invariants (the Klein layer)

**D7 (The double-slit group).** G = the subgroup of PGL(4, ℝ) stabilizing the pair {ℓ₁, ℓ₂}.

**Theorem 5 (Structure and the Erlangen Theorem).**

1. G has two components (identity, and slit-swap); its identity component has dimension 7, versus 15 for the full projective group and 12 for the affine group.
2. G acts on the ray space through the quotient (PGL(2, ℝ) × PGL(2, ℝ)) ⋊ ℤ₂ — independent Möbius actions on the two feet, plus the swap.
3. The kernel of that action is a one-parameter group: the maps fixing every point of both slits. These fix every ray as a set while sliding points along it — a pure **depth gauge**. This is the group-theoretic root of the fact that a single image point carries no depth: depth is precisely the coordinate the image group cannot see.
4. Conversely (fundamental theorem of the geometry), every automorphism of the abstract structure (R, ∥₁, ∥₂, 𝒦) of Theorem 2's classical model is induced by an element of G. (Classical for Miquelian Minkowski planes.)

*Proof sketch for 1–3.* Choose coordinates with ℓ₁ = span(e₀, e₁), ℓ₂ = span(e₂, e₃). The stabilizer of each line separately is the group of block matrices diag(A, B), A, B ∈ GL(2), modulo global scale: dimension 4 + 4 − 1 = 7; the swap is the antidiagonal block. The action on feet is (A, B) acting as Möbius maps on the two ℙ¹'s, a 6-dimensional image; the 1-dimensional kernel is diag(λI, µI), which fixes ℓ₁ and ℓ₂ pointwise and rescales the position along each transversal — the gauge. ∎

**D8 (Bi-cross-ratio).** For four pairwise non-parallel rays r₁, …, r₄ with addresses (sᵢ, tᵢ), set

> ⟦r₁, r₂; r₃, r₄⟧ = (λ, µ),  λ = (s₁, s₂; s₃, s₄),  µ = (t₁, t₂; t₃, t₄),

a point of ℙ¹ × ℙ¹ — equivalently, a single cross-ratio valued in the double numbers ℝ ⊕ ℝ.

**Theorem 6a (Completeness).** The bi-cross-ratio is invariant under G's identity component (the swap exchanges λ and µ), and it is a complete invariant: two 4-tuples of pairwise non-parallel rays are equivalent under the group iff their bi-cross-ratios agree (up to swap).

*Proof.* Invariance: each factor of PGL(2) preserves the cross-ratio on its own slit. Completeness: PGL(2) is sharply 3-transitive on ℙ¹, so a group element matches the first three feet on each slit; the fourth foot is then pinned by the cross-ratio. ∎

Where projective geometry has one number attached to four collinear elements, double-slit geometry has an ordered pair. This doubles the classical special values into a genuinely new taxonomy: a 4-tuple of rays can be harmonic on one slit and generic on the other (λ = −1, µ arbitrary: **split-harmonic**), harmonic on both (**bi-harmonic**, (−1, −1)), harmonic on one and equianharmonic on the other, and so on — configurations with no pinhole analogue, because a pinhole has only one axis of comparison and a double slit has two that never confer.

**Theorem 6b (Chain Criterion).** Four pairwise non-parallel rays lie on a common chain iff λ = µ — iff their double-number cross-ratio lies on the real diagonal. The discrepancy between λ and µ (say λ/µ, or any chosen normalization) is therefore a G-invariant measure of a 4-tuple's failure to be the image of one straight line: its **skew defect**.

*Proof.* If tᵢ = φ(sᵢ) for a Möbius φ, then µ = λ since Möbius maps preserve cross-ratio. Conversely, let φ be the unique Möbius map with φ(sᵢ) = tᵢ for i = 1, 2, 3 (three-point determination). Then (t₁, t₂; t₃, φ(s₄)) = λ = µ = (t₁, t₂; t₃, t₄), and since cross-ratio against three fixed points is injective, φ(s₄) = t₄. ∎ *(Verified numerically: co-chained quadruple gives λ = µ to 10⁻⁹; perturbing one ray off the chain separates them.)* In chain-geometry language this is the classical statement that four points of ℙ¹(ℝ ⊕ ℝ) are concyclic iff their cross-ratio is real.

---

## 6. The Aperture Cross-Ratio Theorem

The theorem that closes the loop between the geometry and the working codec. Recall D6: on the ray through an object point P sit four canonical points — the feet F₁ ∈ ℓ₁, F₂ ∈ ℓ₂ and the screen point S.

**Theorem 7 (Aperture Cross-Ratio Theorem).** Let P be a point off the seam, and let AR(P) denote the ratio of the two magnifications of an infinitesimal round target at P as seen on the screen (horizontal magnification governed by ℓ₁ over vertical governed by ℓ₂ — the codec's measured aspect ratio). Then

> AR(P) = (F₁, F₂; S, P),

the cross-ratio of the four canonical points along P's own ray.

*Proof.* Parametrize the ray by the affine coordinate z of the rig, so F₁, F₂, S, P sit at z = Zv, Zh, 0, z respectively. The two magnifications are Mx = Zv/(z − Zv) and My = Zh/(z − Zh) (V2 spec), so

> AR = Mx/My = (Zv/Zh) · (z − Zh)/(z − Zv) = ((0 − Zv)(z − Zh)) / ((0 − Zh)(z − Zv)) = (F₁, F₂; S, P). ∎

*(Verified numerically to 10⁻¹² across random depths; e.g. at Zv = 150, Zh = 250, z = 350 both sides equal 0.3.)*

**Corollaries.**

1. **The solver is cross-ratio inversion.** Given AR and the three reference points F₁, F₂, S, the point P is recovered as the unique point with that cross-ratio against them — which is why Solver V2.1, z = Zv·Zh·(AR − 1)/(AR·Zh − Zv), is a Möbius function of AR: it is the inverse of a cross-ratio, and cross-ratio against three fixed points is itself a Möbius coordinate. Depth extraction is not merely compatible with projective geometry; it is the oldest projective operation there is, performed along a single ray.
2. **Projective invariance of the measurement.** AR(P) is unchanged by any transformation in G fixing the screen, because cross-ratio is. Size-independence (demo 17) is the infinitesimal expression of this: the invariant belongs to the point and the four-point configuration, not to the target's extent. (For targets of finite size the codec's w/h is a first-order approximation of AR; the exact statement is the infinitesimal one.)
3. **The Jensen bias is Möbius convexity.** z(AR) is strictly convex on the working interval (second derivative positive; verified: ranges ≈ 2.8×10³ to 1.7×10⁴ across AR ∈ [0.25, 0.41] in the rig), so symmetric noise in AR pushes expected depth systematically outward — the +bias measured in the compression gauntlet is a theorem of the geometry, not an artifact of the pipeline.
4. **Why exactly two slits.** The recovery of P needs three reference points on its ray to coordinatize the ray projectively. The double-slit camera supplies precisely three canonical points per ray — one per slit, one from the screen — no more, no fewer. One slit (plus screen) gives two points: not enough; the depth gauge of Theorem 5.3 remains unfixed. The pinhole collapses F₁ = F₂ and loses the coordinate entirely. Two slits is the minimum aperture that makes every ray a measured projective line.

---

## 7. The Hierarchy: Projective, Affine, Calibrated

In Klein's manner, the geometry refines as elements are nominated and the group shrinks:

**Level 1 — Projective double-slit geometry.** Data: {ℓ₁, ℓ₂}. Group: G (dim 7, plus swap). Invariants: incidence, pencils, chains, the bi-cross-ratio, the skew defect. Theorems 1–6 live here.

**Level 2 — Affine double-slit geometry.** Nominate a plane ω (the plane at infinity) meeting the configuration generically. The group drops to G ∩ (affine maps); each ray gains a point at infinity, so ratios along rays become meaningful, and U can be taken as an affine ratio. Parallelism of chains' asymptotic directions appears. This is the level of the (S, T, U) engine chart.

**Level 3 — Calibrated double-slit geometry.** Nominate the screen Π and the metric (the rig: slit depths Zv, Zh, orthogonal slit directions, sensor at z = 0). The group drops to the rig's symmetries; the canonical point S joins F₁, F₂ on every ray, and Theorem 7 turns the aspect ratio into a coordinate. This fuses the two classical metric rungs: the screen supplies the absolute (shape, up to scale), and the actual depths Zv, Zh — or, for stereo, a known baseline — supply the absolute scale that carries it to Euclidean. This is the level of the codec: encoding is evaluating a cross-ratio, transmission is a video stream, decoding is inverting it.

**Theorem 8 (Degeneration Table).** Double-slit geometry contains its neighbors as degenerations of the slit pair:

| Slit configuration | Congruence | Camera | Ray space |
|---|---|---|---|
| two skew lines | hyperbolic | crossed-slits | ℙ¹ × ℙ¹ |
| two lines meeting at a point O | degenerate: bundle through O (+ planar field) | pinhole at O | ℙ² |
| one slit at infinity | parabolic (flavor) | pushbroom | ℙ¹ × 𝔸¹-type chart |
| both slits at infinity | field of parallels | parallel / affine cameras | directions |

The engine's slit-separation control (`main.cpp`, demo 23) walks the first row into the second: as sep → 0 the two slits acquire a common point, non-concurrence fails at exactly one location, and the geometry collapses onto the pinhole — with the bi-cross-ratio's two components fusing into projective geometry's single one. The bowed chains straighten in the same limit, which is what the demo shows.

---

## 8. Dictionary

| Pinhole / projective geometry | Double-slit geometry |
|---|---|
| center of projection (a point) | slit pair (two skew lines) |
| all rays concur at the center | no two generic rays meet (Axiom C2) |
| ray space ℙ² | ray space ℙ¹ × ℙ¹ (a doubly-ruled quadric) |
| coordinatizing algebra ℝ (plane) / ℂ (Möbius) | double numbers ℝ ⊕ ℝ; seam = zero divisors |
| image of a line is a line | image of a line is a chain (Möbius graph; bows) |
| line determined by its image (up to ray) | line determined up to a regulus (Thm 4) |
| cross-ratio λ | bi-cross-ratio (λ, µ); chains ⇔ λ = µ |
| harmonic tetrads | bi-harmonic, split-harmonic, mixed tetrads |
| fundamental group PGL(3) | (PGL(2) × PGL(2)) ⋊ ℤ₂, plus depth gauge |
| depth lost at the center | depth = cross-ratio against F₁, F₂, S (Thm 7) |
| Klein hierarchy: projective ⊃ affine ⊃ Euclidean | Levels 1–3 of §7 |

One closing remark on the tetrahedron. The root tetrahedron of the engine has three pairs of opposite edges: it is not one double-slit geometry but three, sharing a single frame, with the dynamic axis switching of FIG. 6 as the passage between them. The atlas of the Tetra Engine is a triple of Minkowski planes stitched along their seams — and the (S, T, U) round-trip proof of the coordinate system is Level 2 of this hierarchy running in code.

*Verification: `geometry_checks.py` confirms Theorem 3 (line image fits a Möbius graph, residual 2×10⁻¹²), Theorem 6b (λ = µ on chains, λ ≠ µ off), Theorem 7 (AR equals the cross-ratio to 10⁻¹²; Solver V2.1 inverts it exactly), Corollary 7.3 (convexity), and the skewness dichotomy of Axiom C2 on random rays.*
