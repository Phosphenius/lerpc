#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int *str_to_color(const char *str) {    
    int len = strlen(str);
    int *color = malloc((len-1)/2); 
    int j = 0;    
    char *substr = malloc(3);
    
    for(int i=1; i < len; i=i+2) {
        substr[0] = str[i];
        substr[1] = str[i+1];
        substr[2] = '\0';
        sscanf(substr, "%x", &color[j]);
        j++;
    }
    
    free(substr);
    
    return color;
}

int validate_color_str(const char *str) {
    int len = strlen(str);
    
    if(len != 7 || str[0] != 35) {
        return 0;
    }
    
    for(int i = 1; i < len; i++) {
        if(!(str[i] >= 48 && str[i] <= 57) && 
           !(str[i] >= 65 && str[i] <= 70) && 
           !(str[i] >= 97 && str[i] <= 102)) {
            return 0;
        }
    }
    
    return 1;
}

int main(int argc, char **argv) {
    int *a = NULL;
    int *b = NULL;
    int curr = 0;
    int max = 0;
    float t = 0;
                    
    if(argc < 5) {
        fprintf(stderr, "Error: too few arguments\n");
        return -1;
    }
    
    if(!validate_color_str(argv[1]) || !validate_color_str(argv[2])) {
        fprintf(stderr, "Error: invalid color string\n");
        return -1;
    }
    
    a = str_to_color(argv[1]);
    b = str_to_color(argv[2]);
    curr = atoi(argv[3]);
    max = atoi(argv[4]);
    
    t = (float)curr / max;
    
    if(t > 1.0) {
        t = 1.0;
    } else if(t < .0) {
        t = .0;
    }

    for(int i=0; i < 3; i++) {
        a[i] = (b[i] - a[i]) * t + a[i];
    }

    printf("#%02x%02x%02x\n", a[0], a[1], a[2]);
    free(a);
    free(b);
    
    return 0;
}
