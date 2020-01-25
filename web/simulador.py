import requests

while(True):
   valor = int(input("Informe um valor: "))
   r = requests.post("http://casie.herokuapp.com/upload", json={"LUMINOSIDADE":luminosidade})
   print(r.status_code)
