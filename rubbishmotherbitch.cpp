//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>
#include <vector>
#include "rubbishmotherbitch.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
enum vwibor{
per,sca,ot,ro,cc,bez

};
 class tochka
 {
	 protected:
 int xz,yz,xmin,xmax,ymax,ymin,r ;  static int i,qw,vvv;
float nh,nv,alphax,alphay,scale[3][3],trans[3][3],rot[3][3],mul[3],sokranit[3],rot1[3][3],ref[3][3],save[3][3],
 reftr1[3][3],reftr2[3][3],refsc[3][3],scx[3][3],refsc1[3][3],refsc2[3][3],ygol;

vector<float>xarray; vector<float>yarray;  vector<float>xarray1;vector<float>yarray1;
public:
 vwibor tema,self;
 tochka()
 {
 for (int i=0; i < 3; i++) {
	  for (int j=0;j<3;j++){
	  if(i==j){trans[i][j]=1;rot[i][j]=1;rot1[i][j]=1;reftr1[i][j]=1;reftr2[i][j]=1,scx[i][j]=1;}
		  else
		 { trans[i][j]=0; rot[i][j]=0;rot1[i][j]=0;reftr1[i][j]=0;reftr2[i][j]=0,scx[i][j]=0;}
						   }

		   }

 for(int i=0;i<3;i++){mul[i]=0;}

		 for (int i=0; i < 3; i++)
		{
	  for (int j=0;j<3;j++){
		if(i==j&&i!=2){refsc[i][j]=-1;}
		  else if(i==j){refsc[i][j]=1;}
		  else refsc[i][j]=0;
				  }
		  }

	 for (int i=0; i < 3; i++)
		{
	  for (int j=0;j<3;j++){
	  if(i==j){ refsc1[i][j]=1;refsc2[i][j]=1;}
	  else
		 {refsc1[i][j]=0;refsc2[i][j]=0;}
				  }
		  }

 }
 void getinfo(int x,int y,float NH,float NV);
 void center();
 float w2sx(float r);
 float w2sy(float r);
 void line(TImage*im,float x,float y,float x1,float y1);
 void drawaxis(TImage*ie);
 void drawgrid(TImage*ie);
 void number(TImage*ie);
 void drawgraph(TImage*ie,TStringGrid*g,int x1,int y1)
 {
		float x2,y2;
	   ie->Canvas->Brush->Color=clRed;
	 ie->Canvas->Pen->Color=clRed;
	 if(i==0)
		{

			ie->Canvas->MoveTo(x1,y1);
			ie->Canvas->Ellipse(x1-3,y1-3,x1+3,y1+3);

			 x2=s2wx(x1);
			 y2=s2wy(y1);
			g->Cells[0][i]=FloatToStr(x2);
			g->Cells[1][i]=FloatToStr(y2);
			xarray.push_back(StrToFloat(g->Cells[0][i]));
			yarray.push_back(StrToFloat(g->Cells[1][i]));
			i+=1;
		}
		   /*else
		if (check(g,i,x1)==true) {

		 ie->Canvas->LineTo(w2sx(xarray[r]),w2sy(yarray[r]));
		 g->Cells[0][i]=g->Cells[0][r];
		 g->Cells[1][i]=g->Cells[1][r];
		 xarray.push_back(StrToFloat(g->Cells[0][i]));
		 yarray.push_back(StrToFloat(g->Cells[1][i]));
		 i+=1; }*/

		 else
		 {

		 ie->Canvas->LineTo(x1,y1);
		 ie->Canvas->Ellipse(x1-3,y1-3,x1+3,y1+3);
         x2=s2wx(x1);
		 y2=s2wy(y1);
		 g->Cells[0][i]=FloatToStr(x2);
		 g->Cells[1][i]=FloatToStr(y2);
		 xarray.push_back(StrToFloat(g->Cells[0][i]));
		 yarray.push_back(StrToFloat(g->Cells[1][i]));
		 i+=1;
		 }


		}

 bool check(TStringGrid*gri,int size,int x,int y)
 {

 for (unsigned int j=0; j <xarray.size(); j++) {
float p=xarray[j];
float p2=yarray[j];//StrToFloat(gri->Cells[0][j]);
float p1=w2sx(p);
float p3=w2sy(p2);

   if(x>p1-3 && x<=p1+3 && y>p3-3 && y<=p3+3)

   {
	 r=j; return true;
	 }
 }
 return false;
  }


 void points(TStringGrid*w,TStringGrid*c,int x,int y1,vwibor top)
 {
	 static int y=0;
		if(top==per){
	 if(check(c,i,x,y1)==true && y==0){w->Cells[0][0]=c->Cells[0][r];w->Cells[1][y]=c->Cells[1][r];y=y+1; }
	 else if( check(c,i,x,y1)==true && y==1){w->Cells[0][1]=c->Cells[0][r];w->Cells[1][1]=c->Cells[1][r];y=0;
	 }
	  else ShowMessage("selected point is not a vertex");  }


			else if (top==ot)
		   {
		   if(check(c,i,x,y1)==true)
		   {w->Cells[0][0]=c->Cells[0][r];w->Cells[1][0]=c->Cells[1][r];}
			else  ShowMessage("selected point is not a vertex");
		   }

 }

 void setperenos(TStringGrid*gr)
 {

 for (int i=0; i < 3; i++) {
	  for (int j=0;j<3;j++){
	  if(i==j){trans[i][j]=1;}
		  else
		 { trans[i][j]=0;}
						   }
		   }

		 float x2,x1,y2,y1;
		 x2= StrToFloat(gr->Cells[0][1]);
		x1=  StrToFloat(gr->Cells[0][0]);
		y2=StrToFloat(gr->Cells[1][1]);
		y1=StrToFloat(gr->Cells[1][0]);
		trans[2][0]=(x2-x1); trans[2][1]=(y2-y1);


 }
  void perenos(TImage*p,TStringGrid*t,TStringGrid*w,TStringGrid*b,TStringGrid*poin,vwibor rop)
  {
			 del();
		if(rop==bez)
		{
			setperenos(t);
		 for (int i=0; i < 3; i++) {
	  for (int j=0;j<3;j++){

		  w->Cells[j][i]=FloatToStr(trans[i][j]);
						   }

				 }
					}

  if(rop==cc){

		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(w->Cells[j][i].IsEmpty()){w->Cells[j][i]=FloatToStr(trans[i][j]);}
				else {
					trans[i][j]=StrToFloat(w->Cells[j][i]);
				}
			}

		}

		}
	multiplyfinal(mul,trans,poin,b);
	drawfin(p,b);
   }

   void drawfin(TImage*im,TStringGrid*gr)
   {
		  static int u=0;
	 im->Canvas->Brush->Color=clRed;
	 im->Canvas->Pen->Color=clRed;
	 if(gr->Cells[0][0].IsEmpty())return;
	  for(int j=0;j<i;j++)
	  {
		 if(j==0)
		 {
		  im->Canvas->MoveTo(w2sx(StrToFloat(gr->Cells[0][j])),w2sy(StrToFloat(gr->Cells[1][j])));
		  im->Canvas->Ellipse(w2sx(StrToFloat(gr->Cells[0][j]))-3,w2sy(StrToFloat(gr->Cells[1][j]))-3,w2sx(StrToFloat(gr->Cells[0][j]))+3,w2sy(StrToFloat(gr->Cells[1][j]))+3);
		 }
		 else
		 {
		  im->Canvas->LineTo(w2sx(StrToFloat(gr->Cells[0][j])),w2sy(StrToFloat(gr->Cells[1][j])));
		  im->Canvas->Ellipse(w2sx(StrToFloat(gr->Cells[0][j]))-3,w2sy(StrToFloat(gr->Cells[1][j]))-3,w2sx(StrToFloat(gr->Cells[0][j]))+3,w2sy(StrToFloat(gr->Cells[1][j]))+3);
		 }

	  }
	im->Canvas->Brush->Color=clWhite;
   }

   void del()
   {
	   xarray1.clear();
	   yarray1.clear();
   }


   void setpava(float ano)
   {


	   for (int i=0; i < 3; i++) {
	  for (int j=0;j<3;j++){
	  if(i==j){rot[i][j]=1;rot1[i][j]=1;}
		  else
		 {  rot[i][j]=0;rot1[i][j]=0;}
						   }
		   }
	  float x1=cos(ano);
	  float y1=sin(ano);
	  rot[0][0]=x1;
	  rot[1][1]=x1;
	  rot[0][1]= y1;
	  rot[1][0]=-y1;

	   rot1[0][0]=x1;
	  rot1[1][1]=x1;
	  rot1[0][1]= -y1;
	  rot1[1][0]=y1;

   }

	void povorot(TImage*im,TStringGrid*w,TStringGrid*b,TStringGrid*poin,float angle,vwibor rop)
   {         del();

		  if(rop==bez)
		{

	  /*	 for(int i=0;i<3;i++)
	  {
		for(int j=0;j<3;j++)
		{
			if(i==j&& i!=2) {float x=cos(angle*(M_PI/180));
			w->Cells[j][i]=FloatToStrF(x,ffFixed,10,2);rot[i][j]=StrToFloat(w->Cells[j][i]);
							}
			else if(i==0&&j==1||i==1&&j==0){
			float y=sin(angle*(M_PI/180));
			if(i==0){
			w->Cells[j][i]=FloatToStrF(y,ffFixed,10,2);rot[i][j]=StrToFloat(w->Cells[j][i]);
					}
			else if(i==1)	{w->Cells[j][i]=FloatToStrF(-y,ffFixed,10,2);rot[i][j]=StrToFloat(w->Cells[j][i]);
							}
			  else if(i==2&&j==2){rot[i][j]=1;w->Cells[j][i]=FloatToStr(rot[i][j]);}								}
		   else {rot[i][j]=0; w->Cells[j][i]=FloatToStr(rot[i][j]); }
		}
   }
	*/

	setpava(angle);
	   for(int i=0;i<3;i++)
	  {
		for(int j=0;j<3;j++)
		{
		 w->Cells[j][i]=FloatToStr(rot[i][j]);
		}
		  }


		}

  if(rop==cc){

		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(w->Cells[j][i].IsEmpty()){w->Cells[j][i]=FloatToStr(rot[i][j]);}
				else {
					rot[i][j]=StrToFloat(w->Cells[j][i]);
				}
			}

		}

		}
		multiplyfinal(mul,rot,poin,b);
	drawfin(im,b);
	}


  void povorot1(TImage*im,TStringGrid*w,TStringGrid*b,TStringGrid*poin,float angle,vwibor rop)
   {             del();

		  if(rop==bez)
		{
		/*
		 for(int i=0;i<3;i++)
	  {
		for(int j=0;j<3;j++)
		{
			if(i==j&& i!=2) {float x=cos(angle*(M_PI/180));
			w->Cells[j][i]=FloatToStrF(x,ffFixed,10,2);rot1[i][j]=StrToFloat(w->Cells[j][i]);
							}
			else if(i==0&&j==1||i==1&&j==0){
			float y=sin(angle*(M_PI/180));
			if(i==0){
			w->Cells[j][i]=FloatToStrF(-y,ffFixed,10,2);rot1[i][j]=StrToFloat(w->Cells[j][i]);
					}
			else if(i==1)	{w->Cells[j][i]=FloatToStrF(y,ffFixed,10,2);rot1[i][j]=StrToFloat(w->Cells[j][i]);
							}
											}
			else if(i==2&&j==2)  {rot1[i][j]=1; w->Cells[j][i]=FloatToStr(rot1[i][j]);}
		   else {rot1[i][j]=0; w->Cells[j][i]=FloatToStr(rot1[i][j]);}
		}
   }

	 */

     setpava(angle);
	   for(int i=0;i<3;i++)
	  {
		for(int j=0;j<3;j++)
		{
		 w->Cells[j][i]=FloatToStr(rot1[i][j]);
		}
		  }


		}

  if(rop==cc){

		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(w->Cells[j][i].IsEmpty()){w->Cells[j][i]=FloatToStr(rot1[i][j]);}
				else {
					rot1[i][j]=StrToFloat(w->Cells[j][i]);
				}
			}

		}

		}
		multiplyfinal(mul,rot1,poin,b);
	drawfin(im,b);

	}



	void setotrazhenye(TStringGrid*ple)
	{
	float x1,y1;
	  x1= StrToFloat(ple->Cells[0][0]);
		y1=StrToFloat(ple->Cells[1][0]);
	reftr1[2][0]=-x1; reftr1[2][1]=-y1;
	reftr2[2][0]=x1; reftr2[2][1]=y1;

	}

   void pointmashtab(TStringGrid*g1,int x,int y)
   {
	 float x1=s2wx(x);
	 float y1=s2wy(y);
	 g1->Cells[0][0]=FloatToStr(x1);
	 g1->Cells[1][0]=FloatToStr(y1);
   }


		void setmashtab(TStringGrid*ple)
	{
	float x1,y1;
	  x1= StrToFloat(ple->Cells[0][0]);
		y1=StrToFloat(ple->Cells[1][0]);

		if(x1==0&&y1!=0)ygol=3.1415926535897932384626433832795;
        else if(x1==0&&y1==0)ygol=0;
		else {
   ygol=atan((y1/x1));  }


	 for(int i=0;i<3;i++)
	  {
		for(int j=0;j<3;j++)
		{
			if(i==j&& i!=2) {float x=cos(ygol);
			refsc1[i][j]=x; refsc2[i][j]=x;
							}
			else if(i==0&&j==1||i==1&&j==0){
			float y=sin(ygol);
			if(i==0){
			refsc1[i][j]=-y ;refsc2[i][j]=y;
					}
			else if(i==1)	{refsc1[i][j]=y; refsc2[i][j]=-y;
							}
											}
		}

   }




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

	void otraz(TImage*p,TStringGrid*t,TStringGrid*w,TStringGrid*b,TStringGrid*poin,vwibor rop)
  {

	   setotrazhenye(t);

		multi(reftr1,refsc,save);
	   multi(save,reftr2,ref);
		if(rop==bez)  {

		  for (int i=0; i < 3; i++) {
	  for (int j=0;j<3;j++){ w->Cells[j][i]=FloatToStr(ref[i][j]);}

		}
		}

  if(rop==cc){

		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(w->Cells[j][i].IsEmpty()){w->Cells[j][i]=FloatToStr(ref[i][j]);}
				else {
					ref[i][j]=StrToFloat(w->Cells[j][i]);
				}
			}

		}

		}

	multiplyfinal(mul,ref,poin,b);
	drawfin(p,b);


   }



	void mashtabirovanye(TImage*p,TStringGrid*t,TStringGrid*w,TStringGrid*b,TStringGrid*poin,float masho,vwibor rop)
  {


		if(rop==bez)  {
		setmashtab(t);
	   scx[0][0]=masho;
		multi(refsc1,scx,save);
	   multi(save,refsc2,scale);
		  for (int i=0; i < 3; i++) {
	  for (int j=0;j<3;j++){ w->Cells[j][i]=FloatToStr(scale[i][j]);}

		}
		}


  if(rop==cc){

		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(w->Cells[j][i].IsEmpty()){w->Cells[j][i]=FloatToStr(ref[i][j]);}
				else {
					scale[i][j]=StrToFloat(w->Cells[j][i]);
				}
			}

		}

		}

	multiplyfinal(mul,scale,poin,b);
	drawfin(p,b);


   }



 float s2wx(int x);
 float s2wy(int y);
 void multiply1st(float m[3][3],float n[3][3],float jo[3][3],float ans[3][3],float cip[3][3]);
 void multiply2nd(float m[3][3],float n[3][3],float jo[3][3]);
 void multiplyfinal(float muli[3],float transi[3][3],TStringGrid*g11,TStringGrid*g22);
 void pepe(TImage*p,TStringGrid*t,TStringGrid*w,TStringGrid*b,TStringGrid*poin,vwibor rop)
 {

 }

   void ReDrow(TImage* Image)
{
	Image->Canvas->Brush->Color = clWhite;
  	Image->Canvas->FillRect(Image->Canvas->ClipRect);
}


  void Create_Grid(TCheckBox* CB2,TCheckBox* CB3,TCheckBox* CB4,TImage*Image){

		ReDrow(Image);
		if(CB2->Checked){

  Image->Canvas->Pen->Style=psSolid;
   Image->Canvas->Pen->Color=clBlack;

   Image->Canvas->MoveTo(xz,0);
   Image->Canvas->LineTo(xz,nv);
   Image->Canvas->MoveTo(xz,0);
   Image->Canvas->LineTo(xz+3,7);
   Image->Canvas->MoveTo(xz,0);
   Image->Canvas->LineTo(xz-3,7);

   Image->Canvas->MoveTo(0,yz);
   Image->Canvas->LineTo(nh,yz);
   Image->Canvas->LineTo(nh-7,yz+3);
   Image->Canvas->LineTo(nh,yz);
   Image->Canvas->LineTo(nh-7,yz-3);
		}
		if(CB3->Checked){


                 Image->Canvas->Pen->Style=psDot;
	 Image->Canvas->Pen->Color=clBlack;
	 for(int i=0; i<=nh; i+=alphax)
	 {       if(i==(nh/2))continue;
		 Image->Canvas->MoveTo(0,i);
		 Image->Canvas->LineTo(nh,i);
	 }

	 for(int j=0; j<=nv; j+=alphay)
	 {      if(j==(nv/2))continue;
		 Image->Canvas->MoveTo(j,0);
		 Image->Canvas->LineTo(j,nv);
	 }



		}
        if(CB4->Checked){

				int interval_x = this->nh/((this->xmax)-(this->xmin));
				int interval_y = this->nv/((this->ymax)-(this->ymin));

				for(int i = interval_x, count = 1; i < this->nh; i+=interval_x, count++){
						Image->Canvas->TextOutW((this->xz) + i,this->yz,count);
						Image->Canvas->TextOutW((this->xz) - i,this->yz,(-1)*count);
				}
				for(int j = interval_y, count = 1; j < this->nv; j+=interval_y, count++){
						Image->Canvas->TextOutW(this->xz,(this->yz)-j,count);
						Image->Canvas->TextOutW(this->xz,(this->yz)+j,(-1)*count);
				}
		}
}




 };
 int tochka::i=0;
 int tochka::qw=0;
 int tochka::vvv=0;


  void tochka::multiply1st(float m[3][3],float n[3][3],float jo[3][3],float ans[3][3],float cip[3][3])
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


 void tochka::multiply2nd(float m[3][3],float n[3][3],float jo[3][3])
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



 void tochka::multiplyfinal(float muli[3],float transi[3][3],TStringGrid*g11,TStringGrid*g22)
 {
		 static int counter=0; float sok [3]; float sum;
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
				if(counter==0)  { g22->Cells[0][i]=FloatToStr(sok[j]); counter=counter+1;}
				else if(counter==1)  {g22->Cells[1][i]=FloatToStr(sok[j]); counter=counter+1;}
				else {counter=0;}
		}

	 }
 }




 void tochka::getinfo(int x,int y,float NH,float NV)
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
void tochka::center()
{
  xz=(-nh/(xmax-xmin))*xmin;
  yz= (nv/(ymax-ymin))*ymax;
}

   float tochka::w2sx(float r)
	{
   return (floor(alphax*r)+xz);
	}

	 float tochka:: w2sy(float r)
	{
   return (floor(-alphay*r)+yz);
	}
   void tochka::line(TImage*im,float x,float y,float x1,float y1)
	{
		im->Canvas->MoveTo(x,y);
		im->Canvas->LineTo(x1,y1);
	}
	void tochka::drawaxis(TImage*ie)
	{
	ie->Canvas->Pen->Width=2;
	ie->Canvas->Pen->Color=clBlack;
   line(ie,w2sx(xmin),w2sy(0),w2sx(xmax),w2sy(0));
   line(ie,w2sx(0),w2sy(ymin),w2sx(0),w2sy(ymax));
	}

	void tochka::drawgrid(TImage*ie)
	{
	ie->Canvas->Pen->Width=0.5;
	ie->Canvas->Pen->Style=psDot;
	ie->Canvas->Pen->Color=clBlack;
	  for (int i = w2sx(xmin); i <w2sx(xmax); i+=alphax) {
		line(ie,i,w2sy(ymin),i,w2sy(ymax));
	  }
		  for (int i =0;i<xmax-xmin;i++)
		line(ie,w2sx(xmin),0+i*alphay,w2sx(xmax),0+i*alphay);
	}

	void tochka::number(TImage*ie)
	{
		for (int i=0,j=ymax;i<yz-alphay,j>0;i+=alphay,j--) {
				ie->Canvas->TextOutW(xz+3,(0+i)+3,j);
		}

		for (int i=nv,j=ymin;i>yz-alphay,j<0;i-=alphay,j++) {
				ie->Canvas->TextOutW(xz+5,(0+i)-8,j);
		}

			for (int i=nh,j=xmax;i>=0,j>=xmin;i-=alphax,j--) {
				ie->Canvas->TextOutW((i)-5,yz+3,j);
		}

	}

	float tochka::s2wx(int x)
	{
	  return ((x-xz)/alphax);
	}
	float tochka:: s2wy(int y)
	{
	  return (-(y-yz)/alphax);
	}



tochka al;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{


}
//---------------------------------------------------------------------------
void __fastcall TForm1::im1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{



if(cb4->Checked==true)
{

int x=StrToInt(e1->Text);
int y=StrToInt(e2->Text);
al.getinfo(x,y,im2->Width,im2->Height);

  al.drawgraph(im1,sg1,X,Y); }


  else if(rb1->Checked==true)
  {     static int p=0;
	  al.tema=per;

	al.points(sg2,sg1,X,Y,al.tema); p=p+1;
	if(p==2)
	{
/*im2->Canvas->Brush->Color=clWhite;
im2->Canvas->Pen->Width=0.5;
im2->Canvas->Rectangle(0,0,im2->Width,im2->Height);
im2->Canvas->Pen->Style=psSolid;
al.drawaxis(im2);
al.drawgrid(im2);
al.number(im2); */
al.Create_Grid(cb1,cb2,cb3,im2);
al.self=bez;
 al.perenos(im2,sg2,sg3,sg4,sg1,al.self);
 p=0;
	}

  }

	else if (rb2->Checked==true) {

   al.pointmashtab(sg2,X,Y);
  al.self=bez;
/*im2->Canvas->Brush->Color=clWhite;
im2->Canvas->Pen->Width=0.5;
im2->Canvas->Rectangle(0,0,im2->Width,im2->Height);
im2->Canvas->Pen->Style=psSolid;
al.drawaxis(im2);
al.drawgrid(im2);
al.number(im2);*/
al.Create_Grid(cb1,cb2,cb3,im2);
float koe=StrToFloat(e4->Text);
al.mashtabirovanye(im2,sg2,sg3,sg4,sg1,koe,al.self);
  }


  else if(rb3->Checked==true)
  {
	sg2->Rows[1]->Clear();
	al.tema=ot;
	al.points(sg2,sg1,X,Y,al.tema);
/*im2->Canvas->Brush->Color=clWhite;
im2->Canvas->Pen->Width=0.5;
im2->Canvas->Rectangle(0,0,im2->Width,im2->Height);
im2->Canvas->Pen->Style=psSolid;
al.drawaxis(im2);
al.drawgrid(im2);
al.number(im2); */
al.Create_Grid(cb1,cb2,cb3,im2);
al.self=bez;
 al.otraz(im2,sg2,sg3,sg4,sg1,al.self);
  }



/*if(RadioButton1->Checked==true){
	ret1(Image1,StringGrid1,X,Y);}

 if(RadioButton2->Checked==true)
{
	putva(StringGrid1,StringGrid2,X,Y);
	Form1->self=bez;
 otraz(Image2,StringGrid2,StringGrid3,StringGrid4,StringGrid1,Form1->self);
} */

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
/*int x=StrToInt(Edit1->Text);
int y=StrToInt(Edit2->Text);
getinfo(x,y,Image1->Width,Image1->Height);
tochka(); */
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
int x=StrToInt(e1->Text);
int y=StrToInt(e2->Text);
al.getinfo(x,y,im1->Width,im1->Height);
/*im1->Canvas->Brush->Color=clWhite;
im1->Canvas->Pen->Width=0.5;
im1->Canvas->Rectangle(0,0,im1->Width,im1->Height);
im2->Canvas->Rectangle(0,0,im2->Width,im2->Height);
//im1->Canvas->Pen->Style=psSolid;
//im2->Canvas->Pen->Style=psSolid;
if(cb1->Checked==true){im1->Canvas->Brush->Color=clWhite;im1->Canvas->Pen->Width=0.5;im2->Canvas->Pen->Width=0.5;al.drawaxis(im1);al.drawaxis(im2);if(!sg1->Cells[0][0].IsEmpty())al.drawfin(im1,sg1);if(!sg4->Cells[0][0].IsEmpty())al.drawfin(im2,sg4);}
if(cb2->Checked==true){im1->Canvas->Brush->Color=clWhite;im1->Canvas->Pen->Width=0.5;im2->Canvas->Pen->Width=0.5;al.drawgrid(im1);al.drawgrid(im2);if(!sg1->Cells[0][0].IsEmpty())al.drawfin(im1,sg1);if(!sg4->Cells[0][0].IsEmpty())al.drawfin(im2,sg4);}
if(cb3->Checked==true){im1->Canvas->Brush->Color=clWhite;im1->Canvas->Pen->Width=0.5;im2->Canvas->Pen->Width=0.5;al.number(im1);al.number(im2);if(!sg1->Cells[0][0].IsEmpty())al.drawfin(im1,sg1);if(!sg4->Cells[0][0].IsEmpty())al.drawfin(im2,sg4);} */

al.Create_Grid(cb1,cb2,cb3,im1);
al.Create_Grid(cb1,cb2,cb3,im2);
al.drawfin(im1,sg1);
al.drawfin(im2,sg4);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cb1Click(TObject *Sender)
{
  Form1->FormActivate(cb1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cb2Click(TObject *Sender)
{
  Form1->FormActivate(cb2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cb3Click(TObject *Sender)
{
 Form1->FormActivate(cb3);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
int x=StrToInt(e1->Text);
int y=StrToInt(e2->Text);
al.getinfo(x,y,im2->Width,im2->Height);

if(rb1->Checked){
/*im2->Canvas->Brush->Color=clWhite;
im2->Canvas->Pen->Width=0.5;
im2->Canvas->Rectangle(0,0,im2->Width,im2->Height);
im2->Canvas->Pen->Style=psSolid;
al.drawaxis(im2);
al.drawgrid(im2);
al.number(im2); */
al.Create_Grid(cb1,cb2,cb3,im2);
al.self=cc;
 al.perenos(im2,sg2,sg3,sg4,sg1,al.self);
	  }

 else if (rb3->Checked==true) {
  /*im2->Canvas->Brush->Color=clWhite;
im2->Canvas->Pen->Width=0.5;
im2->Canvas->Rectangle(0,0,im2->Width,im2->Height);
im2->Canvas->Pen->Style=psSolid;
al.drawaxis(im2);
al.drawgrid(im2);
al.number(im2);*/
al.Create_Grid(cb1,cb2,cb3,im2);
al.self=cc;
 al.otraz(im2,sg2,sg3,sg4,sg1,al.self);
	  }

 else if (rb4->Checked==true) {
 al.self=cc;
/*im2->Canvas->Brush->Color=clWhite;
im2->Canvas->Pen->Width=0.5;
im2->Canvas->Rectangle(0,0,im2->Width,im2->Height);
im2->Canvas->Pen->Style=psSolid;
al.drawaxis(im2);
al.drawgrid(im2);
al.number(im2); */
al.Create_Grid(cb1,cb2,cb3,im2);
float ang=StrToFloat(e3->Text);
  al.povorot(im2,sg3,sg4,sg1,ang,al.self) ;
	  }

 else if (rb5->Checked==true) {
  al.self=bez;
/*im2->Canvas->Brush->Color=clWhite;
im2->Canvas->Pen->Width=0.5;
im2->Canvas->Rectangle(0,0,im2->Width,im2->Height);
im2->Canvas->Pen->Style=psSolid;
al.drawaxis(im2);
al.drawgrid(im2);
al.number(im2); */
al.Create_Grid(cb1,cb2,cb3,im2);
float ang=StrToFloat(e3->Text);
 al.povorot1(im2,sg3,sg4,sg1,ang,al.self) ;
  }

  else if (rb2->Checked==true) {
  al.self=cc;
/*im2->Canvas->Brush->Color=clWhite;
im2->Canvas->Pen->Width=0.5;
im2->Canvas->Rectangle(0,0,im2->Width,im2->Height);
im2->Canvas->Pen->Style=psSolid;
al.drawaxis(im2);
al.drawgrid(im2);
al.number(im2);*/
al.Create_Grid(cb1,cb2,cb3,im2);
float koe=StrToFloat(e4->Text);
al.mashtabirovanye(im2,sg2,sg3,sg4,sg1,koe,al.self);
  }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::e3Change(TObject *Sender)
{
int x=StrToInt(e1->Text);
int y=StrToInt(e2->Text);
al.getinfo(x,y,im2->Width,im2->Height);

	if (rb4->Checked==true) {
 al.self=bez;
/*im2->Canvas->Brush->Color=clWhite;
im2->Canvas->Pen->Width=0.5;
im2->Canvas->Rectangle(0,0,im2->Width,im2->Height);
im2->Canvas->Pen->Style=psSolid;
al.drawaxis(im2);
al.drawgrid(im2);
al.number(im2);*/
al.Create_Grid(cb1,cb2,cb3,im2);
float ang=StrToFloat(e3->Text);
  al.povorot(im2,sg3,sg4,sg1,ang,al.self) ;
	  }

  else if (rb5->Checked==true) {
  al.self=bez;
/*im2->Canvas->Brush->Color=clWhite;
im2->Canvas->Pen->Width=0.5;
im2->Canvas->Rectangle(0,0,im2->Width,im2->Height);
im2->Canvas->Pen->Style=psSolid;
al.drawaxis(im2);
al.drawgrid(im2);
al.number(im2);  */
al.Create_Grid(cb1,cb2,cb3,im2);
float ang=StrToFloat(e3->Text);
 al.povorot1(im2,sg3,sg4,sg1,ang,al.self) ;
  }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::cb5Click(TObject *Sender)
{
	if(cb5->Checked==true)Timer1->Enabled=true;
	else if(cb5->Checked==false)Timer1->Enabled=false;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  int x=StrToInt(e1->Text);
int y=StrToInt(e2->Text);
al.getinfo(x,y,im2->Width,im2->Height);


if(rb1->Checked){
/*im2->Canvas->Brush->Color=clWhite;
im2->Canvas->Pen->Width=0.5;
im2->Canvas->Rectangle(0,0,im2->Width,im2->Height);
im2->Canvas->Pen->Style=psSolid;
al.drawaxis(im2);
al.drawgrid(im2);
al.number(im2);*/
al.Create_Grid(cb1,cb2,cb3,im2);
al.self=cc;
 al.perenos(im2,sg2,sg3,sg4,sg4,al.self);
	  }

 else if (rb3->Checked==true) {
  /*im2->Canvas->Brush->Color=clWhite;
im2->Canvas->Pen->Width=0.5;
im2->Canvas->Rectangle(0,0,im2->Width,im2->Height);
im2->Canvas->Pen->Style=psSolid;
al.drawaxis(im2);
al.drawgrid(im2);
al.number(im2);*/
al.Create_Grid(cb1,cb2,cb3,im2);
al.self=cc;
 al.otraz(im2,sg2,sg3,sg4,sg4,al.self);
	  }

 else if (rb4->Checked==true) {
 al.self=cc;
/*im2->Canvas->Brush->Color=clWhite;
im2->Canvas->Pen->Width=0.5;
im2->Canvas->Rectangle(0,0,im2->Width,im2->Height);
im2->Canvas->Pen->Style=psSolid;
al.drawaxis(im2);
al.drawgrid(im2);
al.number(im2); */
al.Create_Grid(cb1,cb2,cb3,im2);
float ang=StrToFloat(e3->Text);
  al.povorot(im2,sg3,sg4,sg4,ang,al.self) ;
	  }

 else if (rb5->Checked==true) {
  al.self=bez;
/*im2->Canvas->Brush->Color=clWhite;
im2->Canvas->Pen->Width=0.5;
im2->Canvas->Rectangle(0,0,im2->Width,im2->Height);
im2->Canvas->Pen->Style=psSolid;
al.drawaxis(im2);
al.drawgrid(im2);
al.number(im2);  */
al.Create_Grid(cb1,cb2,cb3,im2);
float ang=StrToFloat(e3->Text);
 al.povorot1(im2,sg3,sg4,sg4,ang,al.self) ;
  }

  else if (rb2->Checked==true) {
  al.self=cc;
/*im2->Canvas->Brush->Color=clWhite;
im2->Canvas->Pen->Width=0.5;
im2->Canvas->Rectangle(0,0,im2->Width,im2->Height);
im2->Canvas->Pen->Style=psSolid;
al.drawaxis(im2);
al.drawgrid(im2);
al.number(im2); */
al.Create_Grid(cb1,cb2,cb3,im2);
float koe=StrToFloat(e4->Text);
al.mashtabirovanye(im2,sg2,sg3,sg4,sg4,koe,al.self);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rb1Click(TObject *Sender)
{
 cb4->Checked=false;
}
//---------------------------------------------------------------------------

