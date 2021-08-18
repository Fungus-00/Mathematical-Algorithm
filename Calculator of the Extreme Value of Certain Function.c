#include    <stdio.h>
#include    <math.h>
double max(double x, double y)
{
	double z;
	if(x>=y) z=x;
	else z=y;
	return z;
}

double min(double x, double y)
{
	double z;
	if(x<=y) z=x;
	else z=y;
	return z;
}


main()
{
    int bound=0,ex=0,mark=0,limit=0,div=0,x=0,y=0;
    double   a,b,c,A,B,C,low,up,mid,d,e,f,g,h,i,j,k,mm=1,nn=1,D,p,q,x1,x2=0,y1,y2=2,sup,inf,test;
    printf("For the function f(x)=(ax^2+bx+c)/(Ax^2+Bx+C),\n");
    printf("input each coefficient of the numerator monomial a,b,c: ");
    scanf("%lf%lf%lf",&a,&b,&c);
    printf("input each coefficient of the denominator monomial A,B,C: ");
    scanf("%lf%lf%lf",&A,&B,&C);
    printf("input the domain as a closed interval: ");
    scanf("%lf%lf",&low,&up);
    mid=max(low,up); low=min(low,up); up=mid;
    if(low==up) bound=-1;   //Programme can omit ordering x and y if so, since they are the same.

    if(A==0 && B==0 && C==0) bound=4;
    else

    if(a==0 && A==0) {
        if(b==0 && B==0) {bound=-1; mm=c/C;}    //#constant function
        else if(B==0) {x=y=1; //#straight line
            mm=(b*low+c)/C;
            nn=(b*up+c)/C;
            if(mm<nn) {x1=low; y1=up;}  //to rank x,y
            else if(low>up) {x1=up; y1=low;}
        }
        else if(b*C==B*c) {d=-C/B; bound=-1; ex=1; mm=b/B;}    //#constant function (without one point)
        else {d=-C/B; //#hyperbola
            if(b==0) j=B;   else j=b/B;
            if((low<d && d<up) || (low==d && d==up)) {bound=3; div=1;}
            else if(low==d) {div=1;
                if(j>0) {bound=x=1; x1=up; mm=(up*b+c)/(up*B+C);}
                else {bound=2; y=1; y1=up; nn=(up*b+c)/(up*B+C);}
            }
            else if(up==d) {div=1;
                if(j>0) {bound=2; y=1; y1=low; nn=(low*b+c)/(low*B+C);}
                else {bound=x=1; x1=low; mm=(low*b+c)/(low*B+C);}
            }
            else {x=y=1;
                mm=(low*b+c)/(low*B+C);
                nn=(up*b+c)/(up*B+C);
                if(mm<nn) {x1=low; y1=up;}  //to rank x,y
                if(mm>nn) {x1=up; y1=low;}
            }
        }
    }
    else

    if(A==0 && B==0) {d=-b/(2*a);   //#parabola
        if(low<=d && d<=up) {
            if(low+up<=d*2) mid=low;
            else mid=up;
            if(a*C>0) {x=1; x1=d;   //The graph goes upwards.
                mm=(a*d*d+b*d+c)/C;
                nn=(a*mid*mid+b*mid+c)/C;
                if(low+up==d*2) {y=2; y1=low; y2=up;}   //to rank x,y
                else {y=1; y1=mid;}
            }
            else {y=1; y1=d;  //The graph goes downwards.
                mm=(a*mid*mid+b*mid+c)/C;
                nn=(a*d*d+b*d+c)/C;
                if(low+up==d*2) {x=2; x1=low; x2=up;}   //to rank x,y
                else {x=1; x1=mid;}
            }
        }
        else {x=y=1;
            mm=(a*low*low+b*low+c)/C;   //monotonic
            nn=(a*up*up+b*up+c)/C;
            if(mm<nn) {x1=low; y1=up;}  //to rank x,y
            if(mm>nn) {x1=up; y1=low;}
		}
    }
    else

    if(A==0) {
        d=-C/B; k=c/a+(b/a+d)*d;

        if(k<0) {j=a/B;   //#function like x-1/x
            if((low<d && d<up) || (low==d && d==up)) {bound=3; div=1;}
            else if(low==d) {div=1;
                if(j>0) {bound=2; y=1; y1=up; nn=(a*up*up+b*up+c)/(B*up+C);}
                else {bound=x=1; x1=up; mm=(a*up*up+b*up+c)/(B*up+C);}
            }
            else if(up==d) {div=1;
                if(j>0) {bound=x=1; x1=low; mm=(a*low*low+b*low+c)/(B*low+C);}
                else {bound=2; y=1; y1=low; nn=(a*low*low+b*low+c)/(B*low+C);}
            }
            else {x=y=1;
                mm=(a*low*low+b*low+c)/(B*low+C);
                nn=(a*up*up+b*up+c)/(B*up+C);
                if(mm<nn) {x1=low; y1=up;}  //to rank x,y
                if(mm>nn) {x1=up; y1=low;}
            }
        } else

        if(k==0) {ex=1; //#straight line (without one point)
            mm=b/B+a/B*(low+d);
            nn=b/B+a/B*(up+d);
            if(low==d && d==up) bound=3;    //The following is to rank x,y.
            else if(low==d) {
                limit=1; p=low; inf=mm;
                if(mm<nn) {bound=2; y=1; y1=nn;}
                if(mm>nn) {bound=1; x=1; x1=nn;}
            }
            else if(up==d) {
                limit=1; p=up; inf=nn;
                if(mm<nn) {bound=1; x=1; x1=mm;}
                if(mm>nn) {bound=2; y=1; y1=mm;}
            }
            else {x=y=1;
                if(mm<nn) {x1=low; y1=up;}
                if(mm>nn) {x1=up; y1=low;}
                }
        }
        
        else {e=sqrt(k); j=a/B;  //#a pair of ticks
            if((low<d && d<up) || (low==d && d==up)) {bound=3; div=1;}
            else if(low==d) {div=1;
                if(j>0) {bound=x=1;
                    if(up<=d+e) {x1=up; mm=(up*b+c)/(up*B+C);}
                    else {x1=d+e; mm=(b+a*(d+e)*2)/B;}
                }
                if(j<0) {bound=2; y=1;
                    if(up<=d+e) {y1=up; nn=(up*b+c)/(up*B+C);}
                    else {y1=d+e; nn=(b+a*(d+e)*2)/B;}
                }
            }
            else if(up==d){div=1;
                if(j>0) {bound=2; y=1;
                    if(d-e<=low) {y1=low; nn=(low*b+c)/(low*B+C);}
                    else {y1=d-e; nn=(b+a*(d-e)*2)/B;}
                }
                if(j<0) {bound=x=1;
                    if(d-e<=low) {y1=low; mm=(low*b+c)/(low*B+C);}
                    else {y1=d-e; mm=(b+a*(d-e)*2)/B;}
                }
            }
            else if(low+e<=d && d<=up+e) {mark=-1; nn=(b+a*(d-e)*2)/B;}	//vertex ordinate of the very tick (the same below)
            else if(low<d+e && d+e<=up) {mark=1; nn=(b+a*(d+e)*2)/B;}
            else {x=y=1;
                mm=(a*low*low+b*low+c)/(B*low+C);
                nn=(a*up*up+b*up+c)/(B*up+C);
                if(mm<nn) {x1=low; y1=up;}  //to rank x,y
                if(mm>nn) {x1=up; y1=low;}
            }
            if(mark!=0) {  //The vertex abscissa of a certain tick is between upper bound and lower bound.
				h=int((a*low*low+b*low+c)/(B*low+C)*pow(2,24)+0.5)/pow(2,24);
				i=int((a*up*up+b*up+c)/(B*up+C)*pow(2,24)+0.5)/pow(2,24);	//To correctly confirm if "i==h", the output accuracy needs reducing.
				if(up<=d+k/(low-d)) mm=h;
                else mm=i;	//The following is to rank x,y.
                if(i==h) {
                    if(mm<nn) {
                        x=2; x1=low; x2=up; y=1;
                        if(mark==-1) y1=d-e;
                        else y1=d+e;
                    }
                    if(mm>nn) {
                        y=2; y1=low; y2=up; x=1;
                        if(mark==-1) x1=d-e;
                        else x1=d+e;
                    }
                }
                else {
                    if(mm<nn) {
                        x=y=1; x1=mid;
                        if(mark==-1) y1=d-e;
                        else y1=d+e;
                    }
                    if(mm>nn) {
                        x=y=1; y1=mid;
                        if(mark==-1) x1=d-e;
                        else x1=d+e;
                    }
                }
            }
        }
    }


    else {e=B/A; f=C/A;
        if(a==0 && b==0 && c==0) {mark=1;} //to sort the funtion by simplifying it
        else if(a==0 && b==0) {mark=2; g=c/A;}
        else if(a==0) {mark=4; g=c/b;}
        else {h=b/a-B/A; g=c/a-C/A;
            if(h==0 && g==0) mark=1;
            else if(h==0) mark=3;
            else {mark=5; g=g/h;}
        }
        
        if(mark==1) {D=e*e-f*4;    //#constant function
            bound=-1; mm=nn=a/A;
            if(D<0) {}
            else if(D==0) {ex=1; d=-e/2;    //to judge if the bound exists (the same below)
                if(low==d && d==up) bound=3;
                else if(low==d) {limit=1; p=low; inf=mm;}
                else if(up==d) {limit=1; p=up; inf=mm;}
        	}
            else {ex=2; sup=inf=mm;
                p=(-e-sqrt(D))/2; q=(-e+sqrt(D))/2;
                if(low==up && (low==p || low==q)) bound=3;
                else if(low==p && q==up) limit=2;
                else if(low==p || up==p) limit=1;
                else if(low==q || up==q) {limit=1; p=q;}
            }
        } else

        else if(mark==2 || mark==3) {
            D=e*e-f*4; d=-e/2;
            if(D<0) {
                if(low<=d && d<=up) {x=1; x1=d;
                    if(low+up<=d*2) mid=low;
                    else mid=up;
                    mm=d*d+e*d+f;
                    nn=mid*mid+e*mid+f;
                    if(low+up==d*2) {y=2; y1=low; y2=up;}   //to rank x,y
                    else {y=1; y1=mid;}
                }
                else {x=y=1;
                    mm=low*low+e*low+f;
                    nn=up*up+e*up+f;
                    if(mm<nn) {x1=low; y1=up;}  //to rank x,y
                    if(mm>nn) {x1=up; y1=low;}
                }
            }
            else if(D==0) {ex=1;    //Function diverges at two points.
                if (low==d && d==up) {bound=3; mark=0;}
                else if(low<d && d<up) {
                    bound=2; div=1;
                    if(low+up==d*2) {y=2; y1=low; y2=up;}   //to rank x,y
                    else if(low+up<d*2) {y=1; y1=low;}
                    else {y=1; y1=up;}
                }
                else {x=y=1;
                    mm=low*low+e*low+f;
                    nn=up*up+e*up+f;
                    if(mm<nn) {x1=low; y1=up;}  //to rank x,y
                    if(mm>nn) {x1=up; y1=low;}
                }
            }
            else {ex=2; //Function diverges at two points.
                p=(-e-sqrt(D))/2; q=(-e+sqrt(D))/2;
                if((low==p && p==up) || (low<=p && q<up) || (low<p && q<=up) || (low==q && q==up)) {bound=3; div=2; mark=0;}
                else if(low<p && p<up) {bound=3; div=1; d=p; mark=0;}
                else if(low<q && q<up) {bound=3; div=1; d=q; mark=0;}
                else if(low==p && up==q) {bound=1; div=2; x=1; x1=d; nn=mm=f-e*e/4;}
                else if(low==p) {bound=div=x=1;
                    if(up<=d) {x1=up; nn=mm=up*up+e*up+f;}
                    else {x1=d; nn=mm=f-e*e/4;}
                    d=p;
                }
                else if(low==q) {bound=2; div=1; y=1; y1=up; nn=mm=up*up+e*up+f; d=q;}
                else if(up==p) {bound=2; div=1; y=1; y1=low; nn=mm=low*low+e*low+f; d=p;}
                else if(up==q) {bound=div=x=1;
                    if(d<=low) {x1=low; nn=mm=low*low+e*low+f;}
                    else {x1=d; nn=mm=f-e*e/4;}
                    d=q;
                }
                else if(p<low && low<=d && d<=up && up<q) {x=1; x1=d;
                    if(low+up<=d*2) mid=low;
                    else mid=up;
                    mm=d*d+e*d+f;
                    nn=mid*mid+e*mid+f;
                    if(low+up==d*2) {y=2; y1=low; y2=up;}   //to rank x,y
                    else if(low+up<d*2) {y=1; y1=low;}
                    else {y=1; y1=up;}
                }
                else {x=y=1;
                    mm=low*low+e*low+f;
                    nn=up*up+e*up+f;
                    if(mm<nn) {x1=low; y1=up;}  //to rank x,y
                    if(mm>nn) {x1=up; y1=low;}
                }
            }
            if(mark==2) {mid=1; mm=g/mm; nn=g/nn;}
            if(mark==3) {mid=a/A; mm=(g/mm+1)*mid; nn=(g/nn+1)*mid;}
            if(mid*g>0) {
                mid=x; x=y; y=mid;
                mid=x1; x1=y1; y1=mid;
                mid=x2; x2=y2; y2=mid;
                if(bound==1) bound=2;
                if(bound==2) bound=1;
            }
        }

        else {D=e*e-f*4; i=e-g*2; k=f+g*(g-e);
            if(D<0) {d=sqrt(k); //since D<0 ==> k>0
                p=-d-g; q=d-g;
                if(low+g<=0 && 0<=up+g) {x=y=1;
                    if(low+g==0) {mm=0; y1=-g;}
                    else if(p<low) {mm=(low+g)/(low*low+e*low+f); y1=low;}
                    else {mm=1/(i-d*2); y1=p;}
                    if(up+g==0) {nn=0; x1=-g;}
                    else if(up<q) {nn=(up+g)/(up*up+e*up+f); x1=up;}
                    else {nn=1/(i+d*2); x1=q;}
                }
                else if(up<=p || (p<=low && up<=q) || q<=low) {x=y=1;
                    mm=(low+g)/(low*low+e*low+f);
                    nn=(up+g)/(up*up+e*up+f);
                    if(mm<nn) {x1=low; y1=up;}  //to rank x,y
                    if(mm>nn) {x1=up; y1=low;}
                }
                else {
                    if(up+g<0) {nn=1/(i-d*2); y=1; y1=p;
                        if(up<k/(low+g)-g) {mid=low; x=1; x1=low;}
                        else if(up==k/(low+g)-g) {mid=low; x=2; x1=low; x2=up;}
                        else {mid=up; x=1; x1=up;}
                    }
                    else {nn=1/(i+d*2); x=1; x1=q;
                        if(up<k/(low+g)-g) {mid=low; y=1; y1=low;}
                        else if(up==k/(low+g)-g) {mid=low; y=2; y1=low; y2=up;}
                        else {mid=up; y=1; y1=low;}
                    }
                    mm=(mid+g)/(mid*mid+e*mid+f);
                }
            }
            if(k==0) { //#hyperbola
                if(D==0) {ex=1; d=-g;   // (k=0 and D=0) ==> e=g*2
                    if((low<d && d<up) || (low==d && d==up)) {bound=3; div=1;}
                    else if(low==d) {div=1; bound=2; y=1; y1=up; nn=mm=1/(up+g);}
                    else if(up==d) {div=1; bound=x=1; x1=low; nn=mm=1/(low+g);}
                    else {x=y=1;
                        mm=1/(low+g);
                        nn=1/(up+g);
                        if(mm<nn) {x1=low; y1=up;}  //to rank x,y
                        if(mm>nn) {x1=up; y1=low;}
                    }
                }
                else {ex=2; d=g-e; p=-g; q=d; inf=1/(e-g*2);
                    if((low<d && d<up) || (low==d && d==up)) {bound=3; div=1;}
                    else if((low+g==0 && up+g==0)) {bound=3;}
                    else if(low==d) {div=1;
                        if(up+g==0) {bound=3; limit=1;}
                        else {bound=2; y=1; y1=up; nn=mm=1/(up+e-g);}
                    }
                    else if(up==d) {div=1;
                        if(low+g==0) {bound=3; limit=1;}
                        else {bound=1; x=1; x1=low; nn=mm=1/(low+e-g);}
                    }
                    else if(low+g==0) {limit=1;
                        if(low<d) {y=1; y1=up; nn=mm=1/(up+e-g);}
                        else {x=1; x1=up; nn=mm=1/(up+e-g);}
                    }
                    else if(up+g==0) {limit=1;
                        if(up<d) {x=1; x1=low; nn=mm=1/(low+e-g);}
                        else {y=1; y1=low; nn=mm=1/(low+e-g);}
                    }
                    else {x=y=1;
                        mm=1/(low+e-g);
                        nn=1/(up+e-g);
                        if(mm<nn) {x1=up; y1=low;}  //to rank x,y
                        if(mm>nn) {x1=low; y1=up;}
                    }
                }
            }
            if(mark==4) {mid=b/A; mm=mm*mid; nn=nn*mid; inf=inf*mid; h=1;}
            else {mid=a/A; mm=(mm*h+1)*mid; nn=(nn*h+1)*mid; inf=(inf*h+1)*mid;}
            if(mid*h>0) {
                mid=x; x=y; y=mid;
                mid=x1; x1=y1; y1=mid;
                mid=x2; x2=y2; y2=mid;
                if(bound==1) bound=2;
                if(bound==2) bound=1;
		    }
        }
    
    }

    
    if(div==0 && limit==0) {mid=min(mm,nn); nn=max(mm,nn); mm=mid;}
    printf("\n--------------------------------\n\n");
    if(bound==-1) printf("min=max=%lf at each point in the domain\n",mm);
    if(bound==0 && x==1) printf("At x=%lf; min=%lf\n",x1,mm);
    if(bound==0 && x==2) printf("At x=%lf,%lf; min=%lf\n",x1,x2,mm);
    if(bound==0 && y==1) printf("At x=%lf; max=%lf\n",y1,nn);
    if(bound==0 && y==2) printf("At x=%lf,%lf; max=%lf\n",y1,y2,nn);
    if(bound==1 && x==1) printf("Maximum doesn't exist\nAt x=%lf; min=%lf\n",x1,mm);
    if(bound==1 && x==2) printf("Maximum doesn't exist\nAt x=%lf,%lf; min=%lf\n",x1,x2,mm);
    if(bound==2 && y==1) printf("Minimum doesn't exist\nAt x=%lf; max=%lf\n",y1,nn);
    if(bound==2 && y==2) printf("Minimum doesn't exist\nAt x=%lf,%lf; max=%lf\n",y1,y2,nn);
    if(bound==3) {
        if(low==up) {printf("Error, invalid function!\n"); div=0;}
        else printf("Error, no extreme value exists!\n");
    }
    if(bound==4) printf("Error, the denominator cannot be zero!\n");
    if(ex==2 || div==2) printf("(No defined value at points x=%lf and x=%lf)\n",p,q);
    else if(ex==1 || div==1) printf("(No defined value at point x=%lf)\n",d);
    if(div==1) printf("f(x) diverges at x=%lf\n",d);
    if(div==2) printf("f(x) diverges at x=%lf and x=%lf\n",p,q);
    if(limit>=1) printf("f(x) converges to %lf at x=%lf",inf,p);
    if(limit==2) printf(", and to %lf at x=%lf",sup,q);
}
