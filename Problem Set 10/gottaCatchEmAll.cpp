#include <iostream> 
#include <stack> 
#include<bits/stdc++.h>
#include <stdlib.h> 
#define intt long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
struct Point {
        double x, y;
};
bool compare(Point a,Point b){
        return a.x<b.x || (a.x==b.x && a.y<b.y);
}
double cross(const Point &O, const Point &A, const Point &B){
        return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
vector<Point> convex_hull(vector<Point> P, int m){
        int n = P.size(), k = 0;
        vector<Point> H(2*n);
        sort(P.begin(), P.end(),compare);
        // Build lower hull
        for (int i = 0; i < n; ++i) {
                while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
                H[k++] = P[i];
        }
        for (int i = n-2, t = k+1; i >= 0; i--) {
                while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
                H[k++] = P[i];
        }
        H.resize(k-1);
        int x0 =0, y0=0, x_t=0, y_t=0;
        if(H.size()<=2) {
            cout<<"-1"<<"\n"; 
            return H;
        }
        x0 = H[0].x;
        y0 = H[0].y;
        x_t = x0;
        y_t = y0;
        long long area_neg = 0, area_sum = 0;
        for(int i=1; i<H.size(); i++){
            double x1 = H[i].x;
            double y1 = H[i].y;
            
            area_sum += (long long)x0*y1;
            area_neg += (long long)x1*y0;
            x0 = x1;
            y0 = y1;
        }
        area_sum += (long long)x0*y_t;
        area_neg += (long long)x_t*y0;
        long long area = (area_sum>area_neg)? (area_sum - area_neg): area_neg-area_sum;
        cout<<area<<"\n";
        return H;
}
int main() 
{   fast;
    int n;
    cin>>n;
    vector <Point> points;
    for(int i=0; i<n; i++){
        intt x, y;
        cin>>x>>y;
        Point point_t;
        point_t.x = x;
        point_t.y = y;
        points.push_back(point_t);
    }
    convex_hull(points, n);
    return 0; 
}