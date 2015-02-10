// $Id: SETUP.C 15916 2012-06-17 09:16:37Z stahlman $

int SETUP() {

   /// Add all the additional libraries here that this package
   /// depends on. (With the same command that loads this package's library...)
   if( gSystem->Load( "libCommonTools" ) == -1 ) return -1;

   return 0;
}
