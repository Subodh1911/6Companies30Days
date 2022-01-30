class Solution {
public:
    double r,x,y;
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        double rd = (double)rand()/RAND_MAX;
        rd = sqrt(rd)*r;
        double t = ((double)rand()/RAND_MAX)*360.0;
        return {x+rd*cos(t),y+rd*sin(t)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */