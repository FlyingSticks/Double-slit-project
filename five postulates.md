# THE FIVE POSTULATES
### Euclid Read Through Two Slits

*A companion note to Double-Slit Geometry — Tetra Engine project*

---

Euclid's *Elements* opens with five postulates: two about drawing lines, one about drawing circles, one asserting that space has no preferred place or direction, and one about parallels. They are the constitution of the plane. This note reads each of them inside the geometry of the double-slit camera — points become rays, lines and circles fuse into chains, congruence becomes the group G of Theorem 5, and the right angle becomes harmonic separation — and records what survives, what improves, and what must be amended. The outcome, stated up front: the first three postulates survive, with the join count shifted and the compass strengthened; the fourth is false as written and must be revised, because in this geometry right angles come in kinds; the fifth stands unchanged in form, while the single word *parallel* beneath it quietly reverses its meaning. Demo 35, the drafting-board construction, is the frontispiece of this note: the sheet on which all five postulates are performed with a straightedge and two disagreeing eyes.

*Every numerical claim below is verified in `check_postulates.py` against the calibrated rig (Zv = 150, Zh = 250, screen z = 0).*

---

## 1 · To join

**Euclid I:** to draw a straight line from any point to any point.

Translate points to rays and lines to chains, and the postulate splits into three facts.

**Postulate I′ (Join).** Any two non-parallel rays lie on a common chain — indeed on a one-parameter pencil of them; any three pairwise non-parallel rays lie on exactly one (Axiom M1). A parallel pair lies on no chain at all.

Two points of Euclid's plane earn a unique line; two rays here earn only a pencil, and uniqueness costs a third ray. This is not a defect but the ordinary economics of circle geometry — two points of the inversive plane likewise share a pencil of circles, and three determine one. What is genuinely new is the exception clause. Euclid keeps parallels offstage until his fifth postulate; in double-slit geometry they gatecrash the first. Two rays sharing a foot are joined by nothing: a chain is the graph of a function of s and cannot take two values at the shared abscissa. The failure has a precise algebraic signature, verified numerically: fit a chain through a triple in which two rays approach 1-parallelism and the fitted map's pole marches onto the shared foot while its determinant falls to zero at the same rate — Theorem 3's case 3 arriving as a limit of case 1, the join degenerating into the cross.

So the first postulate already contains the geometry's parallel theory in miniature. The fifth will only have to name it.

---

## 2 · To produce

**Euclid II:** to produce a finite straight line continuously in a straight line.

A chain is a bidegree-(1, 1) curve in ℙ¹ × ℙ¹ — the graph of a Möbius map — and such a curve is closed: as s runs off either end of the real line the chain converges to the same ray (s, t) = (∞, a/c), verified to seven digits from both sides. Production is therefore always possible, never obstructed, and never finished in Euclid's sense: extend an arc far enough and it returns bearing down on its own starting point. The second postulate holds in the strong, elliptic form. There are no ends of the world to run off; every "line" of the geometry is a topological circle, unbounded yet compact. Euclid demanded that lines be extendable and privately imagined them infinite; the double slit grants the extension and declines the infinity.

---

## 3 · To describe a circle

**Euclid III:** to describe a circle with any centre and distance.

Here the geometry does not merely keep the postulate; it hands Euclid a better compass. Write a chain in coefficients, t = (as + b)/(cs + d) with c ≠ 0, and complete the division:

> (s − q₁)(t − q₂) = ρ,  q₁ = −d/c,  q₂ = a/c,  ρ = (bc − ad)/c².

Every such chain is a **split-circle**: the locus of rays whose address differs from a fixed ray q = (q₁, q₂) by a double number of constant norm N = Δs·Δt = ρ. The center is itself a ray — its first foot is the chain's pole, its second the chain's value at infinity — and the radius is the power ρ, a nonzero real. The converse holds too: any center ray and any nonzero power describe a chain, since the resulting map has determinant −ρ. Both directions are verified numerically. (The identity is classical Minkowski-plane material in the sense of Benz, recalled here rather than claimed.)

**Postulate III′ (Compass).** To describe a chain about any center ray with any nonzero power.

Two footnotes with real content. First, the chains with c = 0 — the straight ones of Theorem 3, case 2 — are exactly the circles whose center has retreated to infinity: Euclid's lines, recovered inside the compass as a limiting aperture, so that Postulates I and III describe one instrument rather than two. Second, the degenerate power. In Euclid the circle of zero radius collapses to its center point. Here it does the opposite: set ρ = 0 and the locus (s − q₁)(t − q₂) = 0 is the union of the two pencils through q — the cross of Theorem 3, case 3, the light cone of the seam algebra. The zero circle does not shrink to the center; it explodes into every ray that shares a foot with it. A compass closed all the way does not vanish — it draws the seam. And because ρ is signed, each center carries two one-parameter families of circles, one per sign: the split signature seen through Euclid's third postulate.

---

## 4 · Right angles — the revision

**Euclid IV:** all right angles are equal to one another.

This is the strangest of the five and the deepest. Its work, as Proclus already saw and Hilbert made structural, is homogeneity: it asserts that a congruence can carry any instance of the fundamental angle onto any other — that the plane has a single, transportable unit. To test it here one must first say what a right angle is in a geometry with no metric. The classical surrogate is harmonic separation: in the Cayley–Klein construction two directions are perpendicular precisely when they harmonically separate the absolute, so "a right angle" is carried by a quadruple with cross-ratio −1.

Now the doubling bites. The invariant of four pairwise non-parallel rays is not a number but the ordered pair ⟦r₁, r₂; r₃, r₄⟧ = (λ, µ) of D8 — one cross-ratio per slit — and Theorem 6a says this pair is a complete invariant: two quadruples are congruent iff their pairs agree, up to the slit swap. Harmonicity therefore splits. A quadruple can be harmonic in one eye and anything at all in the other — **split-harmonic**, (−1, µ) — or harmonic in both: **bi-harmonic**, (−1, −1).

The consequence is fatal to Euclid's sentence. Split-harmonic quadruples form a continuum of congruence classes, one for every value of the spectator modulus µ: a right angle certified by one slit carries a second number the other slit measures, and no motion of the geometry can erase it. This is demonstrated, not merely inferred: for ordered quadruples, sharp 3-transitivity leaves exactly one candidate congruence — the group element matching the first three feet in each factor — and the check script constructs it for a pair with µ ≠ µ′ and watches it miss the fourth foot. In double-slit geometry, right angles come in kinds. Only on the diagonal does Euclid's claim survive:

**Postulate IV′ (Homogeneity, revised).** All bi-harmonic quadruples are equal to one another.

And this survivor is no longer a postulate but a theorem — Theorem 6a transports any (−1, −1) quadruple onto any other, verified across random pairs to 10⁻⁶ — with two honest hedges. It holds up to the slit swap, and gracefully: bi-harmonic is precisely the harmonic class indifferent to which eye is which, the only right angle both eyes co-sign. And it holds off the seam: as two rays of a quadruple approach parallelism the invariant collapses onto the excluded value 1 at rate O(ε), verified across three decades — homogeneity fails exactly on the light cone, where the transporting maps blow up. Euclid's fourth postulate, restated for this geometry: the plane is homogeneous away from the seam, and its transportable unit is the right angle seen twice.

One grace note from the hardware. The rig keeps a harmonic quadruple built in: on the axis, (F₁, F₂; S, P) = −1 at the depth z* = 2·Zv·Zh/(Zv + Zh) = 187.5, the harmonic mean of the slit planes, where the aspect ratio equals −1 exactly — the neutral surface, the dual rig's zero-disparity shape-horopter. The camera carries its unit of right angle the way a theodolite carries a bubble level, and in this geometry that unit is a depth.

---

## 5 · Parallels — one word, reworded

**Euclid V**, in Playfair's equivalent form: through a point not on a given line there passes exactly one line parallel to it.

The fifth postulate survives at two levels, and at both the sentence stands while the word turns over.

For rays — the points of this geometry — parallelism is not one relation but two, ∥₁ and ∥₂, and Playfair holds twice before any chain is drawn: through every ray passes exactly one class of each kind, and classes of opposite kind meet in exactly one ray (Axiom M0, the grid). The parallels of Euclid's plane form a pencil of directions; the parallels here form a woven pair of rulings, and a ray is the unique crossing of its two threads.

For chains, the parallel of circle geometry is the tangent, and the fifth postulate is already an axiom of the system — Axiom M2, the Touching Axiom: if K is a chain, r ∈ K, and q ∉ K is not parallel to r, there is exactly one chain through q meeting K precisely in r. That is Playfair's sentence with *line* replaced by *chain* and *parallel to* replaced by *touching at*. The check script performs it thirty times over: the tangency conditions form a rank-3 linear system, the touching chain exists and is unique, a fine scan finds it meeting K at the single prescribed ray, and the contrasting secant chain through the same q crosses K twice. Exactly one parallel, drawn on demand.

The rewording is beneath the sentence, in the word itself. Euclid's parallels are coplanar lines that never meet. The parallel rays of this geometry are coplanar lines that *do* meet — at the shared foot, on the aperture (The Seam, §1) — and they are precisely the unjoinable pairs, the ones no chain will connect (§4): incidence in the world resurfaces as prohibition in the image. The verification closes the loop in rig coordinates: two 1-parallel rays intersect exactly at their common foot (0, s, Zv) on the vertical slit, while any two rays with distinct feet on both slits are skew, missing each other by

> gap = D·|Δs·Δt| / √(D²Δs² + D²Δt² + (s₁t₂ − s₂t₁)²),  D = Zh − Zv,

so that the split-complex norm N(δ) = Δs·Δt — the algebraic detector of parallelism — is the physical miss distance up to a positive factor, confirmed against brute-force line geometry on two hundred random pairs. Zero norm, zero gap, meeting on the seam, joined by nothing; unit difference, positive gap, meeting nowhere, joined by a pencil.

So the fifth postulate needs no revision at all — only a marginal note. Parallel no longer certifies a separation maintained to infinity; it certifies a meeting held at the aperture. Same sentence, opposite sign.

---

## 6 · Figures

The frontispiece of this note is demo 35, the drafting-board construction: plan and elevation performing the two pinhole halves of the camera on one sheet, the bowed image assembled by transfer, the postulates enacted with straightedge and 45° diagonal. Two interactive figures follow it.

**Figure IV — the transport.** Any bi-harmonic quadruple of rays, grabbed and carried by the unique group element onto the standard one; then a pair of its rays dragged toward parallelism, so the transport can be watched blowing up at the zero divisor — Postulate IV′ and its seam carve-out in one gesture.

**Figure V — the touching.** A chain K and a ray q off it: the unique touching chain through q at a chosen contact ray, played against the pencil of secant chains; beside it, an unjoinable pair, the fitted chain's pole marching onto the shared foot as the join is refused.

---

*Companion to Double-Slit Geometry: Definitions, Axioms, and Theorems. Terms used here — ray, foot, pencil, chain, seam, address, bi-cross-ratio, the axioms C1–C3 and M0–M4, Theorems 3, 5, 6a — are defined there; the incidence inversion is The Seam, §4–5. The split-circle identity of §3 is classical (Benz). Numerical verification of every claim in this note is `check_postulates.py`.*
