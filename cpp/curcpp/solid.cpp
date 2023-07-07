// dependency principle
class Book {
  FileSaver fileSaver; // wrong
  Saver *saver;
}
class Saver {
  virtual void save();
}
