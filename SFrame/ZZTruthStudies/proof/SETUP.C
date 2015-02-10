// $Id: SETUP.C 17003 2012-08-10 12:45:42Z stahlman $

int SETUP() {

   /// Add all the additional libraries here that this package
   /// depends on. (With the same command that loads this package's library...)
   if( gSystem->Load( "libZZTruthStudies" ) == -1 ) return -1;

   return 0;
}
