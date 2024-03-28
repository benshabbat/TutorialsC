char* simplifyPath(char* path) {
    int len = strlen(path);
    char* stack = (char*)malloc((len + 1) * sizeof(char));
    int top = -1;
    char* p = strtok(path, "/");
    while (p != NULL) {
        if (strcmp(p, "..") == 0) {
            if (top >= 0) {
                while (top >= 0 && stack[top] != '/') {
                    top--;
                }
                if (top >= 0) {
                    top--;
                }
            }
        } else if (strcmp(p, ".") != 0 && strcmp(p, "") != 0) {
            stack[++top] = '/';
            strcpy(stack + top + 1, p);
            top += strlen(p);
        }
        p = strtok(NULL, "/");
    }
    if (top == -1) {
        stack[++top] = '/';
    }
    stack[top + 1] = '\0';
    return stack;
}