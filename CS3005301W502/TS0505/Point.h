#include <vector>

class Point {
    private:
    std::vector<float> arr;

    public:
    void Set(int x, int y);
    void Move(int horizontal, int vertical);
    void Rotate();
    void Reflect();

    const float GetHorizontal();
    const float GetVertical();

    Point();
    Point(Point& target);
    ~Point();
};