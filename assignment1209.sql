WITH BOOK_OVERDUE AS (
    SELECT book_id, DATEDIFF(return_date, due_date) AS overdue_days
    FROM BOOK_RENTALS
    WHERE DATEDIFF(return_date, due_date) > 0
)
SELECT b.book_id, COUNT(*) AS overdue_count, AVG(b.overdue_days) AS avg_overdue_days
FROM BOOK_OVERDUE AS b
GROUP BY b.book_id;