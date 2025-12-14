using line_t = long long;

struct Line {
  line_t g, y;
  double x;
};

class LineContainer {
  vector<Line> V;
  double cross(Line a, Line b) {
    return (double)(b.y-a.y)/(a.g-b.g);
  }
public:
  void insert(line_t g, line_t y) {
    Line l = {g, y, 0.0};
    while(V.size()>=2 && cross(l, V[V.size()-2])<=V.back().x)
      V.pop_back();
    if(!V.empty())
      l.x = cross(l, V.back());
    V.push_back(l);
  }
  line_t query(line_t x) {
    int lo = 0, hi = V.size()-1;
    while(lo<hi) {
      int mid = (lo+hi+1)/2;
      if(V[mid].x>x) hi = mid-1;
      else lo = mid;
    }
    return V[lo].g*x+V[lo].y;
  }
} cht;