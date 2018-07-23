#lerpc

Does linear interpolation (lerp) between HTML color codes. 
Example:

```
lerpc "#ff0000" "#00ff00" 42 100
```
Output:
```#936b00```

I personally use this to compute the color for my battery indicator.

## Install
Make sure you have gcc and make installed, then run ```make```

## Run
Signature: __lerpc__ _color1_ _color2_ _current_value_ _max_value_

Colors must be in HTML color code format meaning they consist of a # followed by characters from the intervals [a-f], [A-F] and [0-9]. Alpha colors are not (yet) supported.

