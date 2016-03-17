/**
    * File Name: 10_Container_With_Most_Water.c
    * Author: Louis Xu
    * Mail: louis_xu_ustc@163.com
    * Created Time: 03/17/16
*/

/**
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container.
 */

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize -1, area, maxArea = 0;
    int l, r;

    if (heightSize < 2)
        return maxArea;

    while (left < right) {
        l = height[left];
        r = height[right];
        area = MIN(l, r) * (right - left);
        if (area > maxArea) 
            maxArea = area;
        if (l < r) {
            left++;
            while((left < right) && height[left] < l)
                left++;
        } else {
            right--;
            while((left < right) && height[right] < r)
                right--;
        }
    }

    return maxArea;
}
