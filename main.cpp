#include <iostream>
#include <fstream>
#include <vector>

#include "packet.cpp"
#include "enhanced.cpp"
#include "raw.cpp"

using namespace std;

vector<Packet *> packets;

int catchErr(bool condition, string message)
{
  if (condition)
    cerr << message << endl;
  return 1;
}

void parseFile(string fileName)
{
  ifstream inputFile(fileName);

  catchErr(!inputFile, "Failed to open the input file.");

  string line;
  while (getline(inputFile, line))
  {
    if (line.substr(40, 4) == "AEFE") // Code for Enhanced packet
    {
      Enhanced *e = new Enhanced(line);
      packets.push_back(e);
    }
    else if (line.substr(40, 4) == "88F7") // Code for Raw packet
    {
      Raw *r = new Raw(line);
      packets.push_back(r);
    }
    else
    {
      cerr << "Invalid packet type" << endl;
    }
  }

  inputFile.close(); // Close the input file
}

void writePacketsToFile(string fileName)
{
  ofstream outputFile(fileName);

  catchErr(!outputFile, "Failed to open the output file.");

  int cnt = 0;

  for (Packet *packet : packets)
  {
    packet->printPacketInfo(cnt, outputFile);
    delete packet; // Free memory allocated for each packet
    cnt++;
  }

  outputFile.close(); // Close the output file
}

int main()
{
  parseFile("input_packets.txt");
  writePacketsToFile("output_packets.txt");

  return 0;
}