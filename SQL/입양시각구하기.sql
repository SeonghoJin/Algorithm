select HOUR(DATETIME), count(*) as hour from ANIMAL_OUTS
where HOUR(DATETIME) >= 9 && HOUR(DATETIME) <= 19
GROUP by HOUR(DATETIME)
ORDER by HOUR(DATETIME)