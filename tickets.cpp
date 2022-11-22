#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <iterator>
#include <cstdlib>
//#include <string>
using namespace std;

class Flights
{
    private: 
       int flight_number;
       string departure;
       string destination;
       string date;
       string time;
       int fseats;
       int f_seats;
       int bseats;
       int b_seats;
       int eseats;
       int e_seats;
       int select_Eseats;
       int select_Bseats;
       int select_Fseats;

    public:
    
    Flights(){};

        void setflight_number(int flight_number)
        {
            this->flight_number = flight_number; 

        }
        void setdeparture(string departure)
        {
            this->departure = departure;
        }
        void setdestination(string destination)
        {
            this->destination = destination;
        }
        void setdate(string date)
        {
            this->date = date;
        }
        void settime(string time)
        {
            this->time = time;
        }
        void setfseats(int fseats)
        {
            this->fseats = fseats;
        }
        void setf_seats(int f_seats)
        {
            this->f_seats = f_seats;
        }
        void setbseats(int bseats)
        {
            this->bseats = bseats;
        }
        void setb_seats(int b_seats)
        {
            this->b_seats = b_seats;
        }
        void seteseats(int eseats)
        {
            this->eseats = eseats;
        }
        void sete_seats(int e_seats)
        {
            this->e_seats = e_seats;
        }
        void setSelectESeats(int select_Eseats)
        {
            this->select_Eseats = select_Eseats;
        }
        void setSelectBseats(int select_Bseats)
        {
            this->select_Bseats = select_Bseats;
        }
        void setSelectFseats(int select_Fseats)
        {
            this->select_Fseats = select_Fseats;
        }
        void setCurrentSeats()
        {
            this->f_seats = 1;
            this->b_seats = (this->fseats *(this->select_Eseats + this->select_Bseats + this->select_Fseats)) + 1;
            this->e_seats = (this->fseats *(this->select_Eseats + this->select_Bseats + this->select_Fseats)+(this->bseats *(this->select_Eseats + this->select_Bseats + this ->select_Fseats))) + 1;
        }
        void increaseF()
        {
            this->f_seats++;
        };
        void increaseB()
        {
            this->b_seats++;
        };
        void increaseE()
        {
            this->e_seats++;
    
        };
  

        int getFlightNumber()
        {
            return flight_number;
        }
        string getDeparture()
        {
            return departure;
        }
        string getDestination()
        {
            return destination;
        }
        string getDate()
        {
            return date;
        }
        string getTime()
        {
            return time;
        }

        int getfSeat()
        {
            return fseats;
        }
        int getf_seat()
        {
            return f_seats;
        }
        int geteSeat()
        {
            return eseats;
        }
        int gete_seats()
        {
            return e_seats;
        }
        int getbSeat()
        {
            return bseats;
        }
        int getb_seats()
        {
            return b_seats;
        }

        int getTotalFseats()
        {
            return fseats *(this->select_Eseats + this->select_Bseats + this->select_Fseats);
        }
        int getTotalBseats()
        {
            return bseats *(this->select_Eseats + this->select_Bseats + this->select_Fseats);
        }
        int getTotalEseats()
        {
            return eseats *(this->select_Eseats + this->select_Bseats + this->select_Fseats);
        }
        int getSelectEseats()
        {
            return select_Eseats;
        }
        int getSelectBseats()
        {
            return select_Bseats;
        }
        int getSelectFseats()
        {
            return select_Fseats;
        }
        int getTotalSeats()
        {
            return (this->select_Eseats + this->select_Bseats + this->select_Fseats);
        }
};
     
class Bookings
{
    private:
    int booking_number;
    string date;
    string time;
    string departure;
    string destination;
    string seatclass;
    string firstName;
    string lastName;

    public:
    Bookings(){};

    void setbooking_number(int booking_number)
    {
        this->booking_number = booking_number;
    }
    void setdate(string date)
    {
        this->date = date;
    }
    void settime(string time)
    {
        this->time = time;
    }
    void setdeparture(string departure)
    {
        this->departure = departure;
    }
    void setdestination(string destination)
    {
        this->destination = destination;
    }
    void setSeatClass(string seatclass)
    {
        this->seatclass = seatclass;
    }
    void setFirstName(string firstName)
    {
        this->firstName = firstName;
    }
    void setLastName(string lastName)
    {
        this->lastName = lastName;
    }



    int getNumber()
    {
        return this->booking_number;
    }
    string getDate()
    {
        return this->date;
    }
    string getTime()
    {
        return this->time;
    }
    string getDeparture()
    {
        return this->departure;
    }
    string getDestination()
    {
        return this->destination;
    }
    string getSeatClass()
    {
        return this->seatclass;
    }
    string getFisrtName()
    {
        return this->firstName;
    }
    string getLastName()
    {
        return this->lastName;
    }


};

class FlighInformations
{
    list<Flights *>flightsList;
   
    public:
    FlighInformations(){};
    void readFlightInformations(string file)
    {
        ifstream flightInformations(file);
        string storeFlights;

        if(flightInformations.is_open())
        {
            while(getline(flightInformations, storeFlights) && !flightInformations.eof())
            {
                cout << storeFlights << endl;
                stringstream myFlightInformations(storeFlights);
                string store;
                Flights *f = new Flights;
                int flightStore = atoi(store.c_str());
                getline(flightInformations, store, ',');
                f->setflight_number(atoi(store.c_str()));

                getline(flightInformations, store, ',');
                f->setdeparture(store);

                getline(flightInformations, store , ',');
                f->setdestination(store);

                getline(flightInformations, store , ',');
                f->setdate(store);

                getline(flightInformations, store , ',');
                f->settime(store);

                getline(flightInformations, store, ',');
                flightStore = atoi(store.c_str());
                f->setfseats(flightStore);

                getline(flightInformations, store, ',');
                flightStore = atoi(store.c_str());
                f->setbseats(flightStore);

                getline(flightInformations, store , ',');
                flightStore = atoi(store.c_str());
                f->seteseats(flightStore);

                flightsList.push_back(f);

            }

            flightInformations.close();
            
        }
         
    
        else{
            std::cerr << "The file it's unable to open" << std::endl;
        }
    }

     list<Flights *> getFlightList()
     {
        return flightsList;
     }
};


class BookingsInformations
{
    private:
    list<Bookings *>bookingsList;

    public:
    void readBookingsInformations(string myfile)
    {
        ifstream bookingInformations(myfile);
        string storeBookings;

        if(bookingInformations.is_open())
        {
            while(getline(bookingInformations, storeBookings) && storeBookings.empty())
            {
                cout << storeBookings << endl;
                stringstream bookingInformations(storeBookings);
                string store;
                Bookings *b = new Bookings;
                int bookingStore = atoi(store.c_str());
                getline(bookingInformations, store, ',');
                b->setbooking_number(atoi(store.c_str()));
                
                getline(bookingInformations, store, ',');
                b->setdeparture(store);

                getline(bookingInformations, store , ',');
                b->setdestination(store);

                getline(bookingInformations, store , ',');
                b->setdate(store);

                getline(bookingInformations, store , ',');
                b->settime(store);

                getline(bookingInformations, store , ',');
                b->setSeatClass(store);

                getline(bookingInformations, store, ',');
                b->setFirstName(store);

                getline(bookingInformations, store);
                b->setLastName(store);

                bookingsList.push_back(b);

                
            }

            bookingInformations.close();
        }
    }
    list<Bookings *> getBookingList()
    {
        return bookingsList;
    }

};

void  createTickets (list<Flights *>flightsList , list<Bookings *>bookingsList)
{
        list<Bookings *>::iterator it_bookings;
        list<Flights *>::iterator it_flights;
       
        for(it_bookings = bookingsList.begin(); it_bookings != bookingsList.end(); it_bookings++)
        {
            for(it_flights = flightsList.begin(); it_flights != flightsList.end(); it_flights++)
            {
               Flights *flight = *it_flights;
               Bookings *booking = *it_bookings;

               if(booking->getDate() == flight->getDate() && booking->getTime() == flight->getTime() && booking->getDeparture() == flight->getDeparture() && booking->getDestination() == flight-> getDestination())
               {
                char ticket_name[20];
                snprintf(ticket_name, sizeof(ticket_name), "ticket-%d.txt", booking->getNumber());

                int seat;
                int rows = 1;

                ofstream ticketFile(ticket_name);

                if(booking->getSeatClass() == "first")
                {
                    seat = flight->getfSeat();
                    flight->increaseF();
                }
                 else if (booking->getSeatClass() == "business")
                {
                    seat = flight->getbSeat();
                    flight->increaseB();
                }
                else if (booking->getSeatClass() == "economy")
                {
                    seat = flight->geteSeat();
                    flight->increaseE();
                }
                
                while (seat > (flight->getTotalSeats() * rows))
                {
                    rows++;
                }

                if (ticketFile.is_open())
                {
                   
                    ticketFile << "BOOKING: " << booking->getNumber() << "\nFLIGHT: " << flight->getFlightNumber() << " DEPARTURE: " << booking->getDeparture() << " DESTINATION: " << booking->getDestination() << " " << booking->getDate() << " " << booking->getTime() << "\nPASSENGER: " << booking->getFisrtName() << " " << booking->getLastName() << "\nCLASS: " << booking->getSeatClass() << "\nROW: " << rows << " SEAT: " << seat;
                }
                else
                {
                    std::cerr << "Unable to open file" << std::endl;
                }
               
                ticketFile.close();
               }
            }
        }

};

void allocateSeat(list<Flights *> fList)
{
    list<Flights *>::iterator it;

    ofstream seat("ticket.txt");
    for(it = fList.begin(); it !=fList.end(); it++)
    {
        int row = 0;
        int seat = 0;

    }
};




int main(int argc , char **argv)
{
   
    FlighInformations myFlights;
    myFlights.readFlightInformations("flights.csv");

    BookingsInformations myBookings;
    myBookings.readBookingsInformations("bookings.csv");

    list<Flights *> flightList;
    list<Bookings *> bookingList;

    createTickets(flightList, bookingList);


   
    return 0;

};

       


