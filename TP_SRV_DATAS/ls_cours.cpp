/*~~~~~~~~~~~~~~~~~~~~
Peter SARRITZU
SNIR2
20/12/2023
~~~~~~~~~~~~~~~~~~~~*/
#include <iostream>
#include <iomanip>
#include <string.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

int main(int argc, char* argv[]){
  system("clear");
  sql::Driver *dr;
  sql::Connection *cnx;
  sql::Statement *st;
  sql::ResultSet *res;
  dr = get_driver_instance();
  cnx = dr->connect("localhost", "root", "adminx");
  cnx->setSchema("FORMAPRO");
  st = cnx->createStatement();
  res = st->executeQuery("SELECT * FROM cours;");
  std::cout <<"+-----+---------------------------+"<<std::endl;
  std::cout <<"| NUM | INTITULE                  |"<<std::endl;
  std::cout <<"+-----+---------------------------+"<<std::endl;
  while (res->next()) {
    std::cout << "| " << std::setw(4) << std::left << res->getInt("numco") << "| " << std::setw(26) << std::left << res->getString("intitule") << "|" << std::endl;
  }
  std::cout <<"+-----+---------------------------+"<<std::endl;
  return 0;
}