#ifndef SIMPLEFRACTIONS_H
#define SIMPLEFRACTIONS_H

class simpleFrac {
public:
    int c;
    int z;
    int res;
    simpleFrac(int c, int z) : c(c), z(z) {
        if (z == 0) {
            exit('2');
        }
        if (ceil((float) c / (float) z) == (float) c / (float) z) {
            res = ceil((float) c / (float) z);
        }
    };

    explicit simpleFrac(int c) : c(c), z(1) {

        if (ceil((float) c / (float) z) == (float) c / (float) z) {
            res = ceil((float) c / (float) z);
        }
    };

    string show() {
        if (ceil((float) c / (float) z) == (float) c / (float) z) {
            res = ceil((float) c / z);
            return to_string(res);
        } else {
            return to_string(c) + "/" + to_string(z);
        }
    }

    void div(int d) {
        z *= d;
    }

    void mult(int d) {
        c *= d;
    }

    void div(simpleFrac d) {
        z *= d.c;
        c *= d.z;
    }

    void mult(simpleFrac d) {
        c *= d.c;
        z *= d.z;
    }

    void plus(simpleFrac d) {
        if (z == d.z) {
            c += d.c;
        } else {
            int temp[2];
            temp[0] = d.z;
            temp[1] = z;
            z = d.z = d.z * z;
            c *= temp[0];
            d.c *= temp[1];
            c += d.c;
        }
    }

    void minus(simpleFrac d) {
        if (z == d.z) {
            c -= d.c;
        } else {
            int temp[2];
            temp[0] = d.z;
            temp[1] = z;
            z = d.z = d.z * z;
            c *= temp[0];
            d.c *= temp[1];
            c -= d.c;
        }
    }
   static void conv(simpleFrac &t) {
        int a = t.c;
        int b = t.z;
        if (a < 0)
            a *= -1;
        if (b < 0)
            b *= -1;
        if (b == 0 || a == 0) {
            return;
        }
        while (a - b != 0) {
            if (a > b)
                a -= b;
            else
                b -= a;
        }

        t.c /= a;
        t.z /= b;
        if (t.c < 0 && t.z < 0) {
            t.c /= -1;
            t.z /= -1;
        }
        if (t.c > 0 && t.z < 0) {
            t.c /= -1;
            t.z /= -1;
        }
    };
};

#endif//SIMPLEFRACTIONS_H
