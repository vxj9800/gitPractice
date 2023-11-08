#include <iostream>

using namespace std;
double diff_equ(double y, double t){
      return -(1.0/4.0)*y*t*t;
}


int main()
{
    //innitials
    double t0,y0;
    t0=0;
    y0=1;
    double h=0.5;

    double y_val[100];
    double time[100];

    int i;
    for(i=0;i<=99;++i){
        double f_val1=diff_equ(y0,t0);
        double k1=h*f_val1;

        double f_val2=diff_equ(y0+(k1/2),t0+(h/2));
        double k2=h*f_val2;

        double f_val3=diff_equ(y0+(k2/2),t0+(h/2));
        double k3=h*f_val3;

        double f_val4=diff_equ(y0+k3,t0+h);
        double k4=h*f_val4;

        y0 = y0 + ((1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4));
        y_val[i]=y0;


        t0=t0+0.1;
        time[i]=t0;

    }

    cout << "y_val: ";
    for (int i = 0; i < 100; ++i) {
        cout << y_val[i] << " ";
    }
    cout << endl;

    cout << "time: ";
    for (int i = 0; i < 100; ++i) {
        cout << time[i] << " ";
    }
    cout << endl;



    return 0;
}
