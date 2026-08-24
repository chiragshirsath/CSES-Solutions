WITH AgeGrouped AS (
    -- Step 1: Assign age groups to each member based on their age
    SELECT 
        sport,
        CASE
            WHEN age BETWEEN 5 AND 12 THEN 'Children'
            WHEN age BETWEEN 13 AND 19 THEN 'Teens'
            WHEN age BETWEEN 20 AND 39 THEN 'Adults'
            WHEN age >= 40 THEN 'Seniors'
        END AS age_group
    FROM Members
),
SportCounts AS (
    -- Step 2: Count the number of members for each sport within each age group
    SELECT 
        age_group,
        sport,
        COUNT(*) AS member_count
    FROM AgeGrouped
    WHERE age_group IS NOT NULL
    GROUP BY age_group, sport
),
RankedSports AS (
    -- Step 3: Rank the sports within each age group based on member count
    SELECT 
        age_group,
        sport,
        member_count,
        RANK() OVER (PARTITION BY age_group ORDER BY member_count DESC) AS rnk
    FROM SportCounts
)
-- Step 4: Select only the top-ranked (most popular) sports and order the results
SELECT 
    age_group,
    sport,
    member_count
FROM RankedSports
WHERE rnk = 1
ORDER BY age_group ASC, member_count DESC;