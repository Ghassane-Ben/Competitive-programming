long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
inline long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b)
{
  if (b == 0) return {1, 0, a};
  GCD_type pom = ex_GCD(b, a % b);
  return {pom.y, pom.x - a / b * pom.y, pom.d};
}
//rems are the remainders and mods the respective mods, k is the number of elements
//the function returns the solution of the system and the lcm, since x, x+lcm,x+2*lcm,.. satisfy the system
//complexity O(n*log(lcm))

pair<int, int> chinese(vector<int>&rems, vector<int>&mods, int k) {
  for (int i = 0; i < k; i++) {
    normalize(rems[i], mods[i]);
  }
  int ans = rems[0];
  int mcm = mods[0];
  for (int i = 1; i < k; i++) {
    auto pom = ex_GCD(mcm, mods[i]);
    int x1 = pom.x;
    int d = pom.d;
    if ((rems[i] - ans) % d != 0) {
      return { -1, -1};
    }
    ans = normalize(ans + x1 * (rems[i] - ans) / d % (mods[i] / d) * mcm, mcm * mods[i] / d);
    mcm = LCM(mcm, mods[i]);
  }
  return {ans, mcm};
}


int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int>num = {2, 3};
  vector<int>rem = {4, 5};

  debug() << imie(chinese(num, rem, 2));
}
