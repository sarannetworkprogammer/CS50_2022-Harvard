SELECT name
FROM people
WHERE id IN (
SELECT DISTINCT directors.person_id
FROM directors JOIN movies on movies.id = directors.movie_id
WHERE id in (SELECT movie_id
FROM ratings
WHERE rating >= "9.0"))

