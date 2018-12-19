#ifndef slic3r_FillSmooth_hpp_
#define slic3r_FillSmooth_hpp_

#include "../libslic3r.h"

#include "FillBase.hpp"

namespace Slic3r {

class FillSmooth : public Fill
{
public:
    FillSmooth() {
		nbPass = 2;
		anglePass[0] = float(M_PI/4);
		anglePass[1] = -float(M_PI/4);
		anglePass[2] = 0;
		fillPattern[0] = InfillPattern::ipRectilinear;
		fillPattern[1] = InfillPattern::ipRectilinear;
		fillPattern[2] = InfillPattern::ipRectilinear;
		rolePass[0] = erSolidInfill;
		rolePass[1] = erTopSolidInfill;
		rolePass[2] = erSolidInfill;
		percentWidth[0] = 0.9;
		percentWidth[1] = 2;
		percentWidth[2] = 1.0;
		percentFlow[0] = 0.7;
		percentFlow[1] = 0.3;
		percentFlow[2] = 0.0;
		double extrusionMult = 1.0;
		percentFlow[0] *= extrusionMult;
		percentFlow[1] *= extrusionMult;
		percentFlow[2] *= extrusionMult;
	}
    virtual Fill* clone() const { return new FillSmooth(*this); }

	virtual Polylines fill_surface(const Surface *surface, const FillParams &params);
    virtual void fill_surface_extrusion(const Surface *surface, const FillParams &params,
        const Flow &flow, const ExtrusionRole &role, ExtrusionEntitiesPtr &out);
	
protected:
	int nbPass=2;
	double percentWidth[3];
	double percentFlow[3];
	float anglePass[3];
	ExtrusionRole rolePass[3];
	InfillPattern fillPattern[3];
};


class FillSmoothTriple : public FillSmooth
{
public:
	FillSmoothTriple() {
		nbPass = 3;
		anglePass[0] = float(M_PI / 4);
		anglePass[1] = -float(M_PI / 4);
		anglePass[2] = float(M_PI / 12); //align with nothing
		fillPattern[0] = InfillPattern::ipRectilinear;
		fillPattern[1] = InfillPattern::ipConcentric;
		fillPattern[2] = InfillPattern::ipRectilinear;
		rolePass[0] = erSolidInfill;
		rolePass[1] = erSolidInfill;
		rolePass[2] = erTopSolidInfill;
		percentWidth[0] = 0.8;
		percentWidth[1] = 1.5;
		percentWidth[2] = 2.8;
		percentFlow[0] = 0.7;
		percentFlow[1] = 0.2;
		percentFlow[2] = 0.1;
		double extrusionMult = 1.0;
		percentFlow[0] *= extrusionMult;
		percentFlow[1] *= extrusionMult;
		percentFlow[2] *= extrusionMult;
	}
	virtual Fill* clone() const { return new FillSmoothTriple(*this); }

};

class FillSmoothHilbert : public FillSmooth
{
public:
	FillSmoothHilbert() {
		nbPass = 2;
		anglePass[0] = 0;
		anglePass[1] = -float(M_PI / 4);
		anglePass[2] = float(M_PI / 4);
		fillPattern[0] = InfillPattern::ipHilbertCurve; //ipHilbertCurve
		fillPattern[1] = InfillPattern::ipRectilinear;
		fillPattern[2] = InfillPattern::ipRectilinear;
		rolePass[0] = erSolidInfill;
		rolePass[1] = erSolidInfill;
		rolePass[2] = erTopSolidInfill;
		percentWidth[0] = 1.0;
		percentWidth[1] = 1.0;
		percentWidth[2] = 1.0;
		percentFlow[0] = 0.8;
		percentFlow[1] = 0.1;
		percentFlow[2] = 0.1;
		double extrusionMult = 1.0;
		percentFlow[0] *= extrusionMult;
		percentFlow[1] *= extrusionMult;
		percentFlow[2] *= extrusionMult;
	}
	virtual Fill* clone() const { return new FillSmoothHilbert(*this); }

};


} // namespace Slic3r

#endif // slic3r_FillSmooth_hpp_
