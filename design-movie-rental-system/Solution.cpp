// https://leetcode.com/problems/design-movie-rental-system

class MovieRentingSystem {
 public:
  const static int NMAX = 10001, SMAX = 300001;
  set<pair<int, int>> unrentedmovies[NMAX];
  vector<pair<int, int>> prices[SMAX];
  set<tuple<int, int, int>> rented;
  MovieRentingSystem(int /*n*/, vector<vector<int>>& entries) {
    for (auto& v : entries) {
      int shop = v[0], movie = v[1], price = v[2];
      unrentedmovies[movie].insert({price, shop});
      prices[shop].push_back({movie, price});
    }
    for (auto& p : prices) sort(p.begin(), p.end());
  }

  vector<int> search(int movie) {
    vector<int> ret;
    for (auto sit = unrentedmovies[movie].begin();
         sit != unrentedmovies[movie].end() and ret.size() < 5; ++sit) {
      ret.push_back(sit->second);
    }
    return ret;
  }

  void rent(int shop, int movie) {
    int p = lower_bound(prices[shop].begin(), prices[shop].end(),
                        make_pair(movie, 0))
                ->second;
    unrentedmovies[movie].erase({p, shop});
    rented.insert({p, shop, movie});
  }

  void drop(int shop, int movie) {
    int p = lower_bound(prices[shop].begin(), prices[shop].end(),
                        make_pair(movie, 0))
                ->second;
    unrentedmovies[movie].insert({p, shop});
    rented.erase({p, shop, movie});
  }

  vector<vector<int>> report() {
    vector<vector<int>> ret;
    for (auto sit = rented.begin(); sit != rented.end() and ret.size() < 5;
         ++sit) {
      auto [p, s, m] = *sit;
      ret.push_back({s, m});
    }
    return ret;
  }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
