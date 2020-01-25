import requests

while(True):
   valor = int(input("Informe um valor: "))
   r = requests.post("http://casie.herokuapp.com/upload")
   print(r.status_code)
