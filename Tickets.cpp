#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <iterator>
#include <cstdlib>

using namespace std;

/*! Flight class */

class Flights
{
    private: 
       /*!flight data-file structure*/
       int flight_number; /**< an integer for number of flights*/
       string departure;  /**< a string for flights deparatures*/
       string destination; /**< a string for flights destinations */
       string date; /**< a string for date of flights*/
       string time; /**<a string for time of flights*/
       int fseats; /**< an integer for the maxim number of first class seats*/
       int f_seats; /**< an integer for first class seats */
       int bseats; /**< an integer for the maxim number of business class seats*/
       int b_seats;  /**< an integer for business class seats */
       int eseats; /**< an integer for the maxim number of economy class seats*/
       int e_seats;  /**< an integer for economy class seats */
       int select_Eseats;  /**< an integer for allocated economy class seats */
       int select_Bseats;  /**< an integer for allocated business class seats */
       int select_Fseats;   /**< an integer for allocated first class seats */

    public:
    
    Flights(){};  /*! Constructor */
        
        /**
         * Define setters for flight structure
         * */
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
  
        /**
         * Define getters for flight structure
         * */
         
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

/*! Booking class */   

class Bookings
{
    private:

    /*! booking data-file structure*/

    int booking_number; /**< an integer for number of bookings*/
    string date;  /**< a string for date of bookings*/
    string time; /**< a string for tame of bookings*/
    string departure; /**< a string for departure of bookings*/
    string destination; /**< a string for destination of bookings*/
    string seatclass; /**< a string for class of the seat*/
    string firstName; /**< a string for First Name from bookings*/
    string lastName; /**< a string for Last Name from bookings*/

    public:


    Bookings(){};  /*! Constructor */

      /**
         * Define setters for bookinngs structure
         * */

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
    
      /**
       * Define getters for booking structure
       * */
         
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

/**< Create a class for att store informations from flights file*/

class FlighInformations
{
    list<Flights *>flightsList;
   
    public:
    
    FlighInformations(){}; /*! Constructor */

    /**< Declare getter for flights list*/

    list<Flights *>getFlightList()
    {
        return this->flightsList;
    }

    void readFlightInformations(string file)
    {
        /**< Open file to read from it */
        ifstream flightInformations(file); 
        string storeFlights;

        if(flightInformations.is_open())
        {
            /**< Get line from file to string */
            while(getline(flightInformations, storeFlights) && !flightInformations.eof())
            {
                cout << storeFlights << endl;
                /**< Stringstream string*/
                stringstream myFlightInformations(storeFlights);
                /**< Declare store string and a new object*/
                string store;
                Flights *f = new Flights;
                getline(myFlightInformations, store, ',');
                int flightStore = atoi(store.c_str());
                /**< Call method */ 
                f->setflight_number(flightStore);

                getline(myFlightInformations, store, ',');
                f->setdeparture(store);

                getline(myFlightInformations, store , ',');
                f->setdestination(store);

                getline(myFlightInformations, store , ',');
                f->setdate(store);

                getline(myFlightInformations, store , ',');
                f->settime(store);

                getline(myFlightInformations, store, ',');
                flightStore = atoi(store.c_str());
                f->setfseats(flightStore);

                getline(myFlightInformations, store, ',');
                flightStore = atoi(store.c_str());
                f->setbseats(flightStore);

                getline(myFlightInformations, store , ',');
                flightStore = atoi(store.c_str());
                f->seteseats(flightStore);

                getline(myFlightInformations, store, ',');
                flightStore = atoi (store.c_str());
                f->setSelectESeats(flightStore);

                getline(myFlightInformations, store, ',');
                flightStore = atoi(store.c_str());
                f->setSelectBseats(flightStore);

                getline(myFlightInformations, store , ',' );
                flightStore = atoi(store.c_str());
                f->setSelectFseats(flightStore);

                f->setCurrentSeats();
                
                /**< Add to list*/ 
                flightsList.push_back(f);

            }
            /**< Close file*/
            flightInformations.close();
            
        }
         
    
        else{
            std::cerr << "The file it's unable to open" << std::endl;
        }
    }

     
};

/**< Create a class for att store informations from bookings file*/

class BookingsInformations
{
    private:
    list<Bookings *>bookingsList;

    public:

     /**< Declare getter for bookings list*/
     list<Bookings *>getBookingList()
    {
        return this->bookingsList;
    }
    void readBookingsInformations(string myfile)
    {
        /**< Open file to read from */
        ifstream bookingInformations(myfile);
        string storeBookings;

        if(bookingInformations.is_open())
        {
            /**< Get line from file to string */
           
            while(getline(bookingInformations, storeBookings) && !storeBookings.empty())
            {
                cout << storeBookings << endl;
                stringstream bookingInformations(storeBookings);
                string store;
                Bookings *b = new Bookings;
                int bookingStore = atoi(store.c_str());
                /**< Call method*/ 
                getline(bookingInformations, store, ',');
                b->setbooking_number(atoi(store.c_str()));
                
                getline(bookingInformations, store, ',');
                b->setdate(store);

                getline(bookingInformations, store , ',');
                b->settime(store);

                getline(bookingInformations, store , ',');
                b->setdeparture(store);

                getline(bookingInformations, store , ',');
                b->setdestination(store);

                getline(bookingInformations, store , ',');
                b->setSeatClass(store);

                getline(bookingInformations, store, ',');
                b->setFirstName(store);

                getline(bookingInformations, store);
                b->setLastName(store);
   
                /**< Add to list*/ 
                bookingsList.push_back(b);

                
            }

            /**< Close the file*/
            bookingInformations.close();
        }
        else{
            std::cerr << "The file it's unable to open" << std::endl;
        }
    }
   

};

/**< Make a function for att allocate the seat */

void allocateSeat(list<Flights *> fList)
{
    list<Flights *>::iterator it;

    ofstream seating("ticket.txt");
    for(it = fList.begin(); it !=fList.end(); it++)
    {
        int row = 0;
        int seat = 0;
        Flights *f = *it;

        seating << "Flight" << f->getFlightNumber() << "Departure" << f->getDeparture() << "Destination" << f-> getDestination() << "Date" <<f->getDate() << "Time" <<f->getTime() <<  "\n";
        seating << "first class";

        for(seat = 0 ; seat <= f->getfSeat(); seat++)
        {
            if(seat > (f->getTotalSeats() * row))
            {
                row++;
                seating << "\n";
            }
        }

        seating << "business class";

        for(seat = f->getfSeat() + 1 ; seat <= f->getfSeat() ; seat++)
        {
            if(seat > (f->getTotalSeats() * row))
            {
                 row++;
                seating << "\n";

            }
        }

        seating << "economy class";

        for(seat = f->getfSeat() + f->getbSeat() +1 ; seat <= f->getfSeat() + f->getbSeat() + f->geteSeat(); seat++)
        {
            if (seat > (f->getTotalSeats() * row))
            {
                row++;
                seating << "\n";
               
            }
    }

    seating.close();
    }
};


/**< Make a function for create the tickets*/

void  createTickets (list<Flights *>flightsList , list<Bookings *>bookingsList)
{
        /**<Declare iterators */
        list<Bookings *>::iterator it_bookings;
        list<Flights *>::iterator it_flights;
       
    
       /**< Loop though both lists */ 
        for(it_bookings = bookingsList.begin(); it_bookings != bookingsList.end(); it_bookings++)
        {
           
            for(it_flights = flightsList.begin(); it_flights != flightsList.end(); it_flights++)
            {
                
               Flights *flight = *it_flights;
               Bookings *booking = *it_bookings;
              

               /**< Check if conditions  matching*/ 
    
               if(flight->getDate() == booking->getDate() && flight->getTime() == booking->getTime() && flight->getDeparture() == booking->getDeparture() && flight->getDestination() == booking-> getDestination())
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

                    /**< Write info into ticket */
                   
                    ticketFile << "BOOKING: " << booking->getNumber() << "\nFLIGHT: " << flight->getFlightNumber() << " \nDEPARTURE: " << booking->getDeparture() << " \nDESTINATION: " << booking->getDestination() << " " << booking->getDate() << " " << booking->getTime() << "\nPASSENGER: " << booking->getFisrtName() << " " << booking->getLastName() << "\nCLASS: " << booking->getSeatClass() << "\nROW: " << rows << " SEAT: " << seat;
                }
                else
                {
                    std::cerr << "Unable to open file" << std::endl;
                }
                
                /**< Close file */
                ticketFile.close();
               }
            }
        }

};





int main(int argc , char **argv)
{
   
    FlighInformations myFlights;
    myFlights.readFlightInformations("flights.csv");

    BookingsInformations myBookings;
    myBookings.readBookingsInformations("bookings.csv");


    createTickets(myFlights.getFlightList(), myBookings.getBookingList());
   


   
    return 0;

};

       


