SELECT title AS "Title", summary AS "Summary", prod_year
from film 
INNER JOIN genre ON film.id_genre = genre.id_genre
WHERE genre.name = "detective"
ORDER BY prod_year DESC;