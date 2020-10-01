extern const double YR;

class planet
{
private:
    double X, Y;
    double VX, VY;
    double AX, AY;
    double T;
    double F;

public:
    void set_x( double x ){ X = x; }
    void set_y( double y ){ Y = y; }
    void set_xy( double, double );
    void set_vx( double vx ){ VX = vx; }
    void set_vy( double vy ){ VY = vy; }
    void set_vxy( double, double );
    void set_ax( double ax ){ AX = ax; }
    void set_ay( double ay ){ AY = ay; }
    void set_axy( double, double );
    void set_t( double t ){ T = t; }
    void set_f( double f ){ F = f; }
    void calc_t( void );

    double x( void ){ return X; }
    double y( void ){ return Y; }
    double vx( void ){ return VX; }
    double vy( void ){ return VY; }
    double ax( void ){ return AX; }
    double ay( void ){ return AY; }
    double t( void ){ return T; }
    double f( void ){ return F; }
};