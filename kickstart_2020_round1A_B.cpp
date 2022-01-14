#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cstring>
using namespace std;

class Plate {
public:
  unsigned size;
  unsigned beauty;
  Plate(unsigned size_, unsigned beauty_) : 
    size{size_}, beauty{beauty_} {}
};

unsigned bag[1500 + 500];

int main() {
  int T, N, K, P;
  cin >> T;

  for (int i = 0; i < T; ++i) {
    cin >> N >> K >> P;
    memset(bag, 0, sizeof(bag));

    vector<Plate> plates;
    for (int i = 0; i < N; ++i) {
      plates.clear();

      int cnt = 0, n;
      for (int j = 1; j <= K; ++j) {
        cin >> n;
        cnt += n;
        plates.emplace_back(j, cnt);
      }

      // cout << "Plate stack " << i << endl;
      // for (int j = 0; j < plates.size(); ++j) {
      //   cout << "Plate(" << plates[j].size << ", " << plates[j].beauty << ")" << endl;
      // }

      for (int j = P - 1; j >= 0; --j) {
        if (bag[j] || j == 0) {
          for (int k = 0; k < plates.size(); ++k) {
            bag[j + plates[k].size] = max(bag[j + plates[k].size], bag[j] + plates[k].beauty);
          }
        }
      }
    }
    cout << "Case #" << i + 1 << ": " << bag[P] << endl;
  }
}
