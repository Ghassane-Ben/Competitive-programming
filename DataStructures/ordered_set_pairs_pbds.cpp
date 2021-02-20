#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;


typedef tree <
pair<int, int>,
     null_type,
     less<pair<int, int>>,
     rb_tree_tag,
     tree_order_statistics_node_update > ordered_set;

int t = 0;

ordered_set a;
...
a.insert({x, t++});
a.erase(me.lower_bound({x, 0}));
cout << a.order_of_key({x, 0}) << "\n";