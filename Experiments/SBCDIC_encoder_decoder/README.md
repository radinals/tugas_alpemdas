## Encoder dari ASCII ke SBCDIC dan dari SBCDIC ke ASCII

### Aturan:

| Huruf |  Index   |
|-------|----------|
|   A   |   0001   |
|   R   |   1001   |
|  ...  |   ....   |

| ID |  Tipe   |  Range  |
|----|---------|---------|
| 00 |  Huruf  |  0 - 9  |
| 11 |  Angka  |  A - I  |
| 10 |  Angka  |  J - R  |
| 01 |  Angka  |  S - Z  |
| .. |  ....   |   ...   |

| Id | Index | Karakter |
|----|-------|----------|
| 00 |  0001 |     0    |
| 11 |  0001 |     A    |
| 10 |  0001 |     J    |
| 01 |  0001 |     S    |
| .. |  .... |    ...   |
