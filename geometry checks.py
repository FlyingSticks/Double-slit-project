"""geometry_checks.py -- numerical verification of the theorems in
double_slit_geometry.md against the Tetra rig (Zv=150, Zh=250)."""
import numpy as np
rng = np.random.default_rng(3)
Zv, Zh = 150.0, 250.0
cr = lambda A,B,C,D: ((C-A)*(D-B))/((C-B)*(D-A))

# Theorem 7: AR == (F1,F2;S,P); Solver V2.1 == cross-ratio inversion
for _ in range(50):
    z = rng.uniform(300, 600)
    AR = (Zv/(z-Zv)) / (Zh/(z-Zh))
    assert abs(AR - cr(Zv, Zh, 0.0, z)) < 1e-12
    assert abs(Zv*Zh*(AR-1)/(AR*Zh-Zv) - z) < 1e-9
print("Thm 7 + Cor 7.1: PASS")

# Corollary 7.3: convexity of z(AR) on the working interval
f = lambda a: Zv*Zh*(a-1)/(a*Zh-Zv)
for a in np.linspace(0.25, 0.41, 9):
    h = 1e-4
    assert f(a+h) + f(a-h) - 2*f(a) > 0
print("Cor 7.3 (convexity): PASS")

# Theorem 6b: chain criterion lambda == mu
M = np.array([[1.3,-0.4],[0.7,0.9]])
mob = lambda s: (M[0,0]*s+M[0,1])/(M[1,0]*s+M[1,1])
s = np.array([0.0, 1.0, 2.0, 4.0]); t = mob(s)
assert abs(cr(*s) - cr(*t)) < 1e-9          # on-chain: lambda == mu
lam = cr(*s)
t2 = t.copy(); t2[3] = t[3] + 1.0           # push one ray off the chain
assert abs(lam - cr(*t2)) > 1e-2            # off-chain: lambda != mu
print("Thm 6b (chain criterion): PASS")

# Theorem 3: image of a random line fits a Mobius graph
def ray_st(P):
    px,py,pz = P
    return px*(Zv-Zh)/(pz-Zh), py*(Zh-Zv)/(pz-Zv)
P0 = rng.uniform(-50,50,3)+[0,0,400]; d = rng.uniform(-1,1,3); d[2]+=1.5
S,T = zip(*[ray_st(P0+l*d) for l in np.linspace(-30,30,9)])
S,T = np.array(S), np.array(T)
A = np.stack([S, np.ones_like(S), -S*T, -T],1)
v = np.linalg.svd(A)[2][-1]
assert np.max(np.abs((v[0]*S+v[1])/(v[2]*S+v[3]) - T)) < 1e-8
print("Thm 3 (line -> Mobius graph): PASS")

# Axiom C2: rays with distinct feet on both slits are skew
for _ in range(200):
    s1,t1,s2,t2 = rng.uniform(-5,5,4)
    A1,d1 = np.array([s1,0,Zv]), np.array([-s1,t1,Zh-Zv])
    A2,d2 = np.array([s2,0,Zv]), np.array([-s2,t2,Zh-Zv])
    n = np.cross(d1,d2)
    assert abs(np.dot(A2-A1,n))/np.linalg.norm(n) > 1e-9
print("Axiom C2 (non-concurrence): PASS")
print("ALL GEOMETRY CHECKS PASS")
