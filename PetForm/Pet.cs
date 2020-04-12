using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PetForm
{
    public class Pet
    {
        string name;
        string type;
        int age;

        public string Name { get => name; set => name = value; }
        public string Type { get => type; set => type = value; }
        public int Age { get => age; set => age = value; }

        public Pet(string name, string type, int age)
        {
            this.name = name;
            this.type = type;
            this.age = age;
        }

        public void Walk()
        {
            MessageBox.Show("I am Walking");
        }

        public void Talk()
        {
            MessageBox.Show("I am Talking");
        }
    }

    class Cat : Pet
    {
        public Cat(string name, string type, int age) : base(name, type, age)
        {

        }
    }

    class Dog : Pet
    {
        public Dog(string name, string type, int age) : base(name, type, age)
        {

        }
    }

    interface IReader
    {
        char[] ReadImage(ImageLayout imageLayout)
    }

    class JPGReader : IReader
    {
        public char[] ReadImage(ImageLayout imageLayout)
        {
            throw new NotImplementedException();
        }
    }

    class PNGReader : IReader
    {
        public char[] ReadImage(ImageLayout imageLayout)
        {
            throw new NotImplementedException();
        }
    }
    class GIFReader : IReader
    {
        public char[] ReadImage(ImageLayout imageLayout)
        {
            throw new NotImplementedException();
        }
    }

    abstract class PhotoApplication
    {
        protected IReader reader;

        private char[] thumbNail;

        public abstract void CreateThumbNail();

        public void RenderThumbNail()
        {

        }
    }

    class NiftyPhotoApplication : PhotoApplication
    {
        public NiftyPhotoApplication(IReader reader)
        {
            //Initialise the reader member using the Factory
        }

        public override void CreateThumbNail()
        {
            throw new NotImplementedException();
        }
    }
}
