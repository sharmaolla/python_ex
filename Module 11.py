'''

1. Implement the following class hierarchy using Python:
    A publication can be either a book or a magazine. Each publication has a name.
    Each book also has an author and a page count, whereas each magazine has a chief editor.
    Also write the required initializers to both classes. Create a print_information method to both subclasses
    for printing out all information of the publication in question. In the main program, create publications
    Donald Duck (chief editor Aki Hyyppä) and Compartment No. 6 (author Rosa Liksom, 192 pages).
    Print out all information of both publications using the methods you implemented.

'''

class Publication:
     def __init__(self, name):
         self.name = name

     def print_info(self):
         print(f"Publication name: {self.name}")

class Book(Publication):
    def __init__(self,name,  author, pages):
        super().__init__(name)
        self.author = author
        self.pages = pages

    def print_info(self):
        super().print_info()
        print(f"Author: {self.author} \nNumber of pages: {self.pages}\n")

class Magazine(Publication):
    def __init__(self, name, editor):
        super().__init__(name)
        self.editor = editor

    def print_info(self):
        super().print_info()
        print(f"Chief editor: {self.editor} \n")

publications = []
publications.append(Magazine("Donald Duck","Aki Hyyppä"))
publications.append(Book("Compatment no.6", "Rosa Liksom", 192))

for p in publications:
    p.print_info()



