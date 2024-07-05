import dns.resolver

domain = 'www.baidu.com'
a = dns.resolver.resolve(domain, 'A')
for i in a.response.answer:
    for j in i.items:
        if j.rdtype == 1:
            print(j.address)