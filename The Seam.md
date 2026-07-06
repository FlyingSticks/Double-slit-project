# THE SEAM
### Shared Feet and Exiled Meetings

*A commentary on Axiom C2 of Double-Slit Geometry — companion note to the Tetra Engine project*

---

Axiom C2 states: two distinct rays have a common point if and only if they share a foot, and the common point is then that foot, on the seam. Two phrases in the informal gloss of this axiom — "sharing a foot" and "the meeting is exiled to the seam" — carry the whole mechanism of the geometry. This note unpacks them.

---

## 1 · Sharing a foot, precisely

A ray touches the first slit ℓ₁ at exactly one point, its first foot, and the second slit ℓ₂ at exactly one, its second foot — a transversal that met a slit twice would be that slit. Two rays share a foot when they pass through the same point of the same slit. Now recall the basic fact about lines in space: two distinct lines meet if and only if they are coplanar. For rays, coplanarity has only one way to happen. If two rays pass through the same point p on ℓ₁, they obviously meet there; and the plane they span is forced to contain ℓ₂, because each ray hands that plane one point of ℓ₂ and two points pin the line. That plane is span(p, ℓ₂), and the two rays belong to the flat pencil at p. Conversely, if two rays have distinct feet on both slits, they cannot meet anywhere: a meeting point off the slits would be a scene point threaded by two rays, contradicting the Threading Theorem, and a meeting point on a slit would be a shared foot by definition.

So "sharing a foot" is simultaneously three things: co-pencillary, coplanar, and incident. One small fact closes the case: two distinct rays can share at most one foot, since sharing both would make them the same line. The two parallelisms of the geometry never overlap.

---

## 2 · Where the meetings went

Meetings are not abolished — a camera with no incidences at all could not have pencils, and pencils are its planes. They are sorted and relocated. Count concurrence by how many rays pass through a point:

| Location | Rays through it | Character |
|---|---|---|
| a pinhole center | ∞² — a full bundle | every ray, all at once, at one interior point |
| a seam point | ∞¹ — a pencil | a half-pinhole |
| a generic scene point | exactly 1 | meeting-free interior |

The pinhole spends its entire two-parameter ray budget at a single point. The double slit spends one dimension of concurrence along each slit: every point of the vertical slit is where one image-column's rays cross; every point of the horizontal slit is where one image-row's rays cross. The meetings have been factorized by coordinate — x-meetings deported to one line, y-meetings to the other, at two different depths. That factorization is **anamorphic dissociation**. And it is why depth becomes measurable: the pinhole organizes the image completely, once, at one depth, leaving nothing to compare; the double slit organizes it twice, partially, at Zv and Zh, and the mismatch between the two partial organizations is exactly what the Aperture Cross-Ratio Theorem reads off as the aspect ratio.

---

## 3 · Exile, and the meeting-free interior

"Exiled" also means the scene interior is meeting-free. Off the seam, no two rays ever touch — that is what makes (S, T, U) a coordinate system: no scene point owns two addresses. The addressing fails only on the seam, and it fails in a telling way: a seam point p on ℓ₁ lies on a whole pencil, so its S is determined but its T is free — the address does not vanish, it blows up. Literally: blowing up the two slit lines resolves the singularity, unfolding each seam point into the projective line of rays through it. The point recovers a unique address if one remembers the direction of approach — the excluded seam, found after the fact.

---

## 4 · The inversion in the image

Here is the part most worth staring at. A chain — the image of a straight line — crosses each pencil exactly once, so no chain can contain two rays that share a foot. Meanwhile any two rays with distinct feet on both slits are joined by a one-parameter family of chains. Therefore: **two rays meet in space if and only if no line's image joins them in the picture.** Incidence in the world becomes prohibition in the image. This is precisely the "parallelism" of a Minkowski plane: parallel points are the unjoinable ones. Exile is not mere relocation — the meeting relation crosses over and reappears on the image side wearing the opposite sign.

---

## 5 · The algebra of the seam

The coordinatizing number system says the same thing arithmetically. In the double numbers ℝ ⊕ ℝ, two ray-addresses are joinable when their difference is a unit, parallel when it is a zero divisor — a pair of the form (a, 0) or (0, b). The zero divisors are the seam: meetings live exactly where division fails. This is why the split algebra appears rather than ℂ: the complex numbers have no zero divisors, so Möbius geometry has no parallel points and no seam — the pinhole-family analogue. And since ℝ ⊕ ℝ is the split-complex plane of 1+1 relativity, the zero divisors are its light cone: two rays that meet in space are null-separated in the image. The seam is the picture's light cone.

---

## 6 · A capstone, hedged

One classification result frames the whole discussion, recalled here from classical line geometry and flagged as such: Kummer's study of congruences of order one says that if every scene point is to be threaded by exactly one ray, the aperture has very few options — a point (the pinhole), two skew lines together with their degenerations (this camera, and the pushbroom limit), or the secants of a twisted cubic. The exile constructed here is not one arbitrary choice among many; it is nearly the only alternative geometry permits to the pinhole.

---

*Companion to Double-Slit Geometry: Definitions, Axioms, and Theorems. Terms used here — ray, foot, pencil, chain, seam, Threading Theorem, Aperture Cross-Ratio Theorem, Axiom C2 — are defined there; numerical verification of the underlying claims is in `geometry_checks.py`.*
