#include <algorithm>

/**
 * @class Solution
 * @brief Computes the total area covered by two axis-aligned rectangles.
 *
 * The rectangles are defined by their bottom-left and top-right coordinates.
 * The result is the area of the union of the two rectangles, accounting for
 * any overlapping region.
 *
 * The approach:
 *  - Compute the area of each rectangle independently.
 *  - Compute the width and height of their intersection by clamping overlap
 *    dimensions to zero (to handle disjoint rectangles).
 *  - Subtract the intersection area from the sum of individual areas.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
class Solution {
public:
    /**
     * @brief Calculates the union area of two rectangles.
     *
     * @param ax1 x-coordinate of rectangle A's bottom-left corner
     * @param ay1 y-coordinate of rectangle A's bottom-left corner
     * @param ax2 x-coordinate of rectangle A's top-right corner
     * @param ay2 y-coordinate of rectangle A's top-right corner
     * @param bx1 x-coordinate of rectangle B's bottom-left corner
     * @param by1 y-coordinate of rectangle B's bottom-left corner
     * @param bx2 x-coordinate of rectangle B's top-right corner
     * @param by2 y-coordinate of rectangle B's top-right corner
     *
     * @return Total area covered by both rectangles.
     *
     * @note The overlap width and height are clamped to zero to correctly
     *       handle non-overlapping rectangles without conditional branching.
     */
    int computeArea(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {

        // Area of rectangle A
        int areaA = (ax2 - ax1) * (ay2 - ay1);

        // Area of rectangle B
        int areaB = (bx2 - bx1) * (by2 - by1);

        // Compute overlap dimensions (intersection), clamped to zero
        int overlapWidth  =
            std::max(0, std::min(ax2, bx2) - std::max(ax1, bx1));
        int overlapHeight =
            std::max(0, std::min(ay2, by2) - std::max(ay1, by1));

        int overlapArea = overlapWidth * overlapHeight;

        // Union area = sum of individual areas minus overlapping region
        return areaA + areaB - overlapArea;
    }
};