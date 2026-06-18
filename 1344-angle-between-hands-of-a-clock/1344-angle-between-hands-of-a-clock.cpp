class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h,m;
        if(hour==12){
            h=(minutes*0.5);
        }
        else{
        h=((minutes)*0.5)+(hour*30);
        }
        m=(minutes*6);
        if(abs(h-m)>180){
            return 360-abs(h-m);
        }
        else{
            return abs(h-m);
        }
        return 0;
    }
};