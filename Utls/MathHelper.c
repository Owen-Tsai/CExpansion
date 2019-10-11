/*
 * Math Helper source
 * This file contains helper functions for maths
 *
 * CExpansion MIT Licensed
 * Author: Owen Tsai
 */

int Clamp(int min, int max, int value) {
    if(max < min) exit(ERROR);
    if(value < min) return min;
    if(value > max) return max;
    return value;
}