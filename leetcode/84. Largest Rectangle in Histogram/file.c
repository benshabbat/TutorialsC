int largestRectangleArea(int* heights, int heightsSize) {
    if (heights == NULL || heightsSize == 0) return 0;
    
    int* stack = malloc(sizeof(int) * (heightsSize + 1)); // stack to store indices
    int top = -1; // stack top index
    int maxArea = 0;
    
    for (int i = 0; i <= heightsSize; i++) {
        int currentHeight = (i == heightsSize) ? 0 : heights[i];
        
        while (top >= 0 && currentHeight < heights[stack[top]]) {
            int h = heights[stack[top--]];
            int w = (top == -1) ? i : i - 1 - stack[top];
            maxArea = (h * w > maxArea) ? h * w : maxArea;
        }
        
        stack[++top] = i;
    }
    
    free(stack);
    return maxArea;
}