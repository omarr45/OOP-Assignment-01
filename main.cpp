#include <iostream>
#include <fstream>
#include <vector>

#include "packet.cpp"
#include "enhanced.cpp"
#include "raw.cpp"

using namespace std;

vector<Packet *> packets;

enum packetType
{
  ECPRI,
  RAW,
  INVALID
};

int catchErr(bool condition, string message)
{
  if (condition)
    cerr << message << endl;
  return 1;
}

packetType getPacketType(string line)
{
  if (line.substr(40, 4) == "AEFE")
    return packetType::ECPRI;
  else if (line.substr(40, 4) == "88F7")
    return packetType::RAW;
  else
    return packetType::INVALID;
}

Packet *getPacket(packetType packetType, string line)
{
  if (packetType == packetType::ECPRI)
  {
    return new Enhanced(line);
  }
  else if (packetType == packetType::RAW)
  {
    return new Raw(line);
  }
  else
  {
    cerr << "Invalid packet type." << endl;
    return nullptr;
  }
}

void parseFile(string fileName)
{
  ifstream inputFile(fileName);

  catchErr(!inputFile, "Failed to open the input file.");

  string line;
  while (getline(inputFile, line))
  {
    packetType packetType = getPacketType(line);
    packets.push_back(getPacket(packetType, line));
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