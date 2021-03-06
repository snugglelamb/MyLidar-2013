#include "mbed.h"

/** An interface for a simple, 1-track, incremental encoder. If using a simple reflectance sensor, then a voltage comparator
 *  circuit will be required to generate the pulsetrain.  See: http://www.bot-thoughts.com/2011/03/avc-bot-wheel-encoders.html
 *
 */
class IncrementalEncoder
{
    public:
        /** Create an incremental encoder interface.  Increments counter at every rise and fall signal 
         *
         * @param pin -- the pin to which a digital pulsetrain is sent
         */
        IncrementalEncoder(PinName pin,int id);

        /** Get ticks since last call
         *
         * @returns the number of ticks since the last call to this method
         */        
        unsigned long read();

        /** Get total tick count since last reset
         *
         * @returns total ticks since the last reset or instantiation
         */
        unsigned long readTotal();
       
        /** Reset the tick counter
         *
         */
        void reset();
        
         /** get the speed of the car
         *
         * @returns speed of the car
         */
        float getSpeed();
        
         /** get the period of the encoder
         *
         * @returns period of the encoder
         */
        unsigned long getPeriod();
        
         /** get the total pulse from start. reset will not affect the return of this method
         *
         * @returns total pulse from start
         */
        unsigned long getPulse();
    private:
        unsigned long _lastTicks;
        unsigned long _ticks;
        unsigned long _totalTicks;
        InterruptIn _interrupt;
        void _increment();

        unsigned long _Tlast;
        unsigned long _Tnow;
        int _ID;

        Timer timer;
};