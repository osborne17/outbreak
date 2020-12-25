#ifndef PERSON_H
#define PERSON_H


class person
{
      public:
            int status;	//0->susceptible, 1->infected, 2->recovered
		double recovery_time;
		int vel;
            person();
            int alive_dead(int I,int n);


      protected:

      private:
};

#endif // PERSON_H
