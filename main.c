#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

struct color
{
    int r;
    int g;
    int b;
};

char *str_slice(int start, int end, char *str)
{
    char *result = malloc(sizeof(char) * strlen(str));
    int counter = 0;
    
    for(int i=start; i < end; i++)
    {
        result[counter] = str[i];
        counter++;
    }
    
    return result;
}

void print_color(struct color col)
{
    printf("#%02x%02x%02x\n", col.r, col.g, col.b);
}

int lerp(int a, int b, float t)
{
    return (b - a) * t + a;
}

struct color lerpc(struct color a, struct color b, float t)
{
    a.r = lerp(a.r, b.r, t);
    a.g = lerp(a.g, b.g, t);
    a.b = lerp(a.b, b.b, t);
    
    return a;
}

struct color str_to_color(char *str)
{
    int r = 0;
    int g = 0;
    int b = 0;
    
    sscanf(str_slice(1, 3, str), "%x", &r);
    sscanf(str_slice(3, 5, str), "%x", &g);
    sscanf(str_slice(5, 7, str), "%x", &b);
    
    struct color result = {r, g, b};
    
    return result;
}

bool validate_color_str(char *str)
{
    int len = strlen(str);
    
    if(len != 7 || str[0] != 35)
    {
        return false;
    }
    
    for(int i = 1; i < len; i++)
    {
        if(!(str[i] >= 48 && str[i] <= 57) && 
           !(str[i] >= 65 && str[i] <= 70) && 
           !(str[i] >= 97 && str[i] <= 102))
        {
            return false;
        }
    }
    
    return true;
}

int main(int argc, char **argv) 
{
    struct color a = {0, 0, 0};
    struct color b = {0, 0, 0};
    int curr = 0;
    int max = 0;
    float t = 0;
                    
    if(argc < 5)
    {
        fprintf(stderr, "Error: too few arguments\n");
        return -1;
    }
    
    if(!validate_color_str(argv[1]) || !validate_color_str(argv[2]))
    {
        fprintf(stderr, "Error: invalid color string\n");
        return -1;
    }
    
    a = str_to_color(argv[1]);
    b = str_to_color(argv[2]);
    curr = atoi(argv[3]);
    max = atoi(argv[4]);
    
    t = (float)curr / max;
    
    if(t > 1.0)
    {
        t = 1.0;
    }
    else if(t < .0)
    {
        t = .0;
    }
    
    print_color(lerpc(a, b, t));
    
    return 0;
}
