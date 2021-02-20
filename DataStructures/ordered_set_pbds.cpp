#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;

typedef tree <
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update >
ordered_set;


//come usarlo

ordered_set a;
a.insert(1);
a.insert(5);
cout << *a.find_by_order(1) << endl;
cout << a.order_of_key(5) << endl; // 0

