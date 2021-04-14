#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5 + 5;
struct Vertex {
    Vertex *l, *r;
    int sum;

    Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};
Vertex* version[MAXN];


Vertex* build(int a[], int tl, int tr) {
    if (tl == tr)
        return new Vertex(a[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm + 1, tr));
}

int get_sum(Vertex* v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    int tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
           + get_sum(v->r, tm + 1, tr, max(l, tm + 1), r);
}

Vertex* update(Vertex* v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        return new Vertex(v->sum + new_val); // CHANGE THIS TO ONLY NEWVAL IF YOU WANT TO SET
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm + 1, tr, pos, new_val));
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string ora;
    getline(cin, ora);
    int n = ora[0] - '0';
    int arr[n + 1];
    for (int i = 0; i < n + 1; i++)arr[i] = 0;

    Vertex* nodo = build(arr, 0, n);
    version[0] = nodo;

    for (int i = 0; i < n; i++) {
        string linea;
        getline(cin, linea);
        //debug() << imie(linea);
        int pos1 = -1, pos2 = -1;
        int val1 = 0, val2 = 0;

        for (int j = 0; j < linea.length(); j++) {
            if (linea[j] == '+') {
                if (pos1 == -1) {
                    pos1 = linea[j + 1] - '0';
                    val1 = 1;
                }
                else if (pos2 == -1) {
                    pos2 = linea[j + 1] - '0';
                    val2 = 1;
                }
            }
            else if (linea[j] == '-') {
                if (pos1 == -1) {
                    pos1 = linea[j + 1] - '0';
                    val1 = -1;
                }
                else if (pos2 == -1) {
                    pos2 = linea[j + 1] - '0';
                    val2 = -1;
                }
            }
        }
        //debug() << imie(pos1) imie(val1) imie(pos2) imie(val2) imie(linea)

        if (pos1 != -1 && pos2 == -1) {
            nodo = update(nodo, 0, n, pos1, val1);
            version[i + 1] = nodo;
        }
        else if (pos2 != -1 && pos1 == -1) {
            nodo = update(nodo, 0, n, pos2, val2);
            version[i + 1] = nodo;
        }
        else if (pos2 != -1 && pos1 != -1) {

            nodo = update(nodo, 0, n, pos1, val1);

            nodo = update(nodo, 0, n, pos2, val2);
            version[i + 1] = nodo;
            //debug() << imie(i + 1) imie(current) imie(pos2) imie(val1);

        }
        else {
            version[i + 1] = version[i];

        }


    }
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int giorno;
        cin >> giorno;

        int calc = get_sum(version[giorno], 0, n, sum, n);
        //debug() << imie(calc);s
        sum = (sum + calc) % n;
        //debug() << imie(sum) imie(calc);
    }



    cout << sum << '\n';




}