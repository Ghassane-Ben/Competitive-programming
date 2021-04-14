#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
#include <bits/extc++.h>

struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
#define int long long
struct ordered_multiset { // multiset supporting duplicating values in set
        int len = 0;
        const int ADD = 1000010;
        const int MAXVAL = 1000000010;
        hash_map<int, int> mp; // hash = 96814
        tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;

        ordered_multiset() { len = 0; T.clear(), mp.clear(); }

        inline void insert(int x){
            len++, x += MAXVAL;
            int c = mp[x]++;
            T.insert((x * ADD) + c); }

        inline void erase(int x){
            x += MAXVAL;
            int c = mp[x];
            if(c) {
                c--, mp[x]--, len--;
                T.erase((x*ADD) + c); } }

        inline int kth(int k){        // 1-based index,  returns the
            if(k<1 || k>len) return -1;     // K'th element in the treap,
            auto it = T.find_by_order(--k); // -1 if none exists
            return ((*it)/ADD) - MAXVAL; }

        inline int lower_bound(int x){      // Count of value <x in treap
            x += MAXVAL;
            int c = mp[x];
            return (T.order_of_key((x*ADD)+c)); }

        inline int upper_bound(int x){      // Count of value <=x in treap
            x += MAXVAL;
            int c = mp[x];
            return (T.order_of_key((x*ADD)+c)); }

        inline int size() { return len; }   // Number of elements in treap
    };



int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//USAGE
	ordered_multiset a;
	a.insert(1),a.insert(2),a.insert(3);

	cout<<a.kth(2)<<'\n';

	a.erase(2);
}
