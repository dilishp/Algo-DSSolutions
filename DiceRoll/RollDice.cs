using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DiceRoll
{
    class RollDice
    {
        int numberofSides;
        Random randomSideGen;

        public RollDice()
        {
            this.numberofSides = 6;
            randomSideGen = new Random();
        }

        public RollDice(int noofSides)
        {
            this.numberofSides = noofSides;
            randomSideGen = new Random();
        }

        public int Roll()
        {
            int rndNumber = randomSideGen.Next(1, numberofSides + 1);
            return rndNumber;
        }
    }
}
