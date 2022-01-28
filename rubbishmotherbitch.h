//---------------------------------------------------------------------------

#ifndef rubbishmotherbitchH
#define rubbishmotherbitchH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <iostream.h>
#include <vector>
//---------------------------------------------------------------------------

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TImage *im1;
	TStringGrid *sg1;
	TRadioButton *rb1;
	TRadioButton *rb2;
	TStringGrid *sg2;
	TEdit *e1;
	TEdit *e2;
	TStringGrid *sg3;
	TStringGrid *sg4;
	TImage *im2;
	TCheckBox *cb1;
	TCheckBox *cb2;
	TCheckBox *cb3;
	TCheckBox *cb4;
	TCheckBox *cb5;
	TRadioButton *rb3;
	TRadioButton *rb4;
	TRadioButton *rb5;
	TEdit *e3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *e4;
	TLabel *Label4;
	TTimer *Timer1;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	void __fastcall im1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall cb1Click(TObject *Sender);
	void __fastcall cb2Click(TObject *Sender);
	void __fastcall cb3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall e3Change(TObject *Sender);
	void __fastcall cb5Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall rb1Click(TObject *Sender);
private:
 /*static int counter,exist;
 int xz,yz,xmin,xmax,ymax,ymin,r ;  static int i,qw,vvv;
float nh,nv,alphax,alphay;
 vector<int>xycod;
  float ref[3][3],save[3][3],
 reftr1[3][3],reftr2[3][3],refsc[3][3],mul[3]; */
public:
__fastcall TForm1(TComponent* Owner);
/*vwibor tema,self;
void tochka()
{
    for (int i=0; i < 3; i++) {
	  for (int j=0;j<3;j++){
	  if(i==j){reftr1[i][j]=1;reftr2[i][j]=1;}
		  else
		 {  reftr1[i][j]=0;reftr2[i][j]=0;}
						   }
		   }

 for (int i=0; i < 3; i++)
		{
		   for(int j=0;j<3;j++)
		   {
			   refsc[i][j]=0;
           }

		  }

 refsc[0][0]=-1; refsc[1][1]=-1;refsc[2][2]=1;
   mul[2]=1;
}
void ret(TImage*im,TStringGrid*gr,int x,int y);
bool check(TImage*um,int x,int y);
 void ret1(TImage*im,TStringGrid*gr,int x,int y);
 bool retval(int x,TStringGrid*pp)
{
   for(int k=0;k<xycod.size();k++)
   {

   int yp=xycod[k];
	   if(x>yp&&x<=yp+8) {exist=k;return true; }
}
return false;
}

void putva(TStringGrid*gr,TStringGrid*s2,int x,int y)
{

 if(retval(x,gr)==true){s2->Cells[0][0]=gr->Cells[0][exist];
 s2->Cells[1][0]=gr->Cells[1][exist];}
}


 void multiply1st(float m[3][3],float n[3][3],float jo[3][3],float ans[3][3],float cip[3][3]);
 void multiply2nd(float m[3][3],float n[3][3],float jo[3][3]);
 void multiplyfinal(float muli[3],float transi[3][3],TStringGrid*g11,TStringGrid*g22);

  float s2wx(int x);
 float s2wy(int y);
   void getinfo(int x,int y,float NH,float NV);
void center();
float w2sx(float r);
 float w2sy(float r);


 void drawfin(TImage*im,TStringGrid*gr)
   {
		  static int u=0;
	 im->Canvas->Brush->Color=clBlack;
	  for(int j=0;j<counter;j++)
	  {
		 if(j==0)
		 {
		  im->Canvas->MoveTo(w2sx(StrToFloat(gr->Cells[0][j])),w2sy(StrToFloat(gr->Cells[1][j])));
		  im->Canvas->Rectangle(w2sx(StrToFloat(gr->Cells[0][j])),w2sy(StrToFloat(gr->Cells[1][j])),w2sx(StrToFloat(gr->Cells[0][j]))+7,w2sy(StrToFloat(gr->Cells[1][j]))+7);
		 }
		 else
		 {
		  im->Canvas->LineTo(w2sx(StrToFloat(gr->Cells[0][j])),w2sy(StrToFloat(gr->Cells[1][j])));
		  im->Canvas->Rectangle(w2sx(StrToFloat(gr->Cells[0][j])),w2sy(StrToFloat(gr->Cells[1][j])),w2sx(StrToFloat(gr->Cells[0][j]))+7,w2sy(StrToFloat(gr->Cells[1][j]))+7);
		 }

	  }

   }






 void setotrazhenye(TStringGrid*ple)
	{
	float x1,y1;
	  x1= StrToFloat(ple->Cells[0][0]);
		y1=StrToFloat(ple->Cells[1][0]);
	reftr1[2][0]=-x1; reftr1[2][1]=-y1;
	reftr2[2][0]=x1; reftr2[2][1]=y1;

	}


 void otraz(TImage*p,TStringGrid*t,TStringGrid*w,TStringGrid*b,TStringGrid*poin,vwibor rop)
  {

	   setotrazhenye(t);
		if(rop==bez)  {
		  multi(reftr1,refsc,save);
		  multi(save,reftr2,ref);
          for (int i=0; i < 3; i++) {
	  for (int j=0;j<3;j++){ w->Cells[j][i]=FloatToStrF(ref[i][j],ffFixed,10,1);}

		}
		}
	   /*	{ for (int i=0; i < 3; i++) {
	  for (int j=0;j<3;j++){

		 { w->Cells[j][i]=FloatToStrF(ref[i][j],ffFixed,10,1);}
						   }
				  }
					}

  if(rop==cc){

		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(w->Cells[j][i].IsEmpty()){w->Cells[j][i]=FloatToStrF(ref[i][j],ffFixed,10,1);}
				else {
					ref[i][j]=StrToFloat(w->Cells[j][i]);
				}
			}

		}

		}

	multiplyfinal(mul,ref,poin,b);
	drawfin(p,b);

   }
 void multi(float m1[3][3],float m2[3][3],float m3[3][3])
 {
 float sum;
   for(int p=0;p<3;p++)
   {

	   for(int j=0;j<3;j++)
		 {
			 sum=0;
		  for(int k=0;k<3;k++)
		  {
			  sum+=m1[p][k]*m2[k][j];
          }
		  m3[p][j]=sum;

         }
   }

 }
	*/


};



/*int TForm1::counter=0;
int TForm1::exist=0;


void TForm1::ret1(TImage*im,TStringGrid*gr,int x,int y)
{
  im->Canvas->Brush->Color=clBlack;
if(counter==0)
{
im->Canvas->MoveTo(x,y);
im->Canvas->Rectangle(x,y,x+8,y+8);
gr->Cells[0][counter]=FloatToStrF(s2wx(x),ffFixed,10,1);
gr->Cells[1][counter]=FloatToStrF(s2wy(y),ffFixed,10,1);
xycod.push_back(x);
counter=counter+1;
}

	  else {
	 im->Canvas->LineTo(x,y);
	 im->Canvas->Rectangle(x,y,x+8,y+8);
	 gr->Cells[0][counter]=FloatToStrF(s2wx(y),ffFixed,10,1);
	 gr->Cells[1][counter]=FloatToStrF(s2wy(y),ffFixed,10,1);
	 xycod.push_back(x);
	 counter=counter+1; }

}

void TForm1::multiply1st(float m[3][3],float n[3][3],float jo[3][3],float ans[3][3],float cip[3][3])
  {
	  static int l=0;
 if(l==2){ return;}

  for(int i=0;i<3;i++)
  {
        for (int j=0;j<3;j++)
            {
				  float sum=0;
                  for (int k=0;k<3;k++)
                  sum=sum+(m[i][k]*n[k][j]);
                   jo[i][j]=sum;
              }
   }
   l+=1;
   multiply1st(jo,ans,cip,ans,cip);
  }


 void TForm1::multiply2nd(float m[3][3],float n[3][3],float jo[3][3])
 {
   for(int i=0;i<3;i++)
  {
        for (int j=0;j<3;j++)
            {
				  float sum=0;
                  for (int k=0;k<3;k++)
                  sum=sum+(m[i][k]*n[k][j]);
                   jo[i][j]=sum;
              }
   }

 }



 void TForm1::multiplyfinal(float muli[3],float transi[3][3],TStringGrid*g11,TStringGrid*g22)
 {
		 static int counter1=0; float sok [3]; float sum;
	  for (int i=0;i<g11->RowCount;i++)
	 {
	   if(g11->Cells[0][i].IsEmpty()) break;
	   muli[0]=StrToFloat(g11->Cells[0][i]);
	   muli[1]=StrToFloat(g11->Cells[1][i]);
	   muli[2]=1;

		for(int j=0;j<3;j++)
		{
			  sum=0;
			for(int k=0;k<3;k++)
				   {
				sum+=muli[k]*transi[k][j];    }
				   sok [j]=sum;
				if(counter1==0)  { g22->Cells[0][i]=FloatToStrF(sok[j],ffFixed,10,1); counter1=counter1+1;}
				else if(counter1==1)  {g22->Cells[1][i]=FloatToStrF(sok[j],ffFixed,10,1); counter1=counter1+1;}
				else {counter1=0;}
		}

	 }
 }

 void TForm1::getinfo(int x,int y,float NH,float NV)
{
  xmax=x;
   xmin=-x;
   ymax=y;
   ymin=-y;
   nh=NH;
   nv=NV;
   center();
   alphax=(nh/(xmax-xmin));
   alphay=(nv/(ymax-ymin));
}
void TForm1::center()
{
  xz=(-nh/(xmax-xmin))*xmin;
  yz= (nv/(ymax-ymin))*ymax;
}

   float TForm1::w2sx(float r)
	{
   return (floor(alphax*r)+xz);
	}

	 float TForm1:: w2sy(float r)
	{
   return (floor(-alphay*r)+yz);
	}


	float TForm1::s2wx(int x)
	{
	  return ((x-xz)/alphax);
	}
	float TForm1:: s2wy(int y)
	{
	  return (-(y-yz)/alphax);
	}  */

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
