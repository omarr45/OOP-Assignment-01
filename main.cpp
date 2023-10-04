#include <iostream>
#include <fstream>
#include <vector>

#include "packet.cpp"
#include "enhanced.cpp"
#include "raw.cpp"

using namespace std;

int main()
{
  ifstream inputFile("input_packets.txt");
  if (!inputFile)
  {
    cerr << "Failed to open the input file." << endl;
    return 1;
  }

  vector<Packet *> packets;

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

  ofstream outputFile("output_packets.txt");

  if (!outputFile)
  {
    cerr << "Failed to open the output file." << endl;
    return 1;
  }

  int cnt = 0;

  for (Packet *packet : packets)
  {
    packet->printPacketInfo(cnt, outputFile);
    delete packet; // Free memory allocated for each packet
    cnt++;
  }

  outputFile.close(); // Close the output file

  return 0;
}