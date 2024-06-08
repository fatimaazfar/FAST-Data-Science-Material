document.addEventListener('DOMContentLoaded', () => {
    const jobApplicationForm = document.getElementById('jobApplicationForm');
    const viewApplicationsBtn = document.getElementById('viewApplicationsBtn');
    const applicationsTable = document.getElementById('applicationsTable');
    const applicationsData = [];

    jobApplicationForm.addEventListener('submit', (event) => {
        event.preventDefault(); // Prevent the form from submitting the traditional way
        
        // Object to hold form data
        const formData = {
            fullName: jobApplicationForm.firstName.value + ' ' + jobApplicationForm.lastName.value,
            email: jobApplicationForm.email.value,
            phoneNumber: jobApplicationForm.phoneNumber.value,
        };
        
        // Validate form data
        if (!jobApplicationForm.checkValidity()) {
            alert('Please fill in all required fields.');
            return;
        }
        
        // Add the validated form data to our applications data array
        applicationsData.push(formData);
        
        // Optionally, clear the form
        jobApplicationForm.reset();
        
        // Log out the applications data array to the console
        console.log(applicationsData);
    });

    viewApplicationsBtn.addEventListener('click', () => {
        // Generate table rows from applications data
        const tableBody = applicationsTable.querySelector('tbody');
        tableBody.innerHTML = ''; // Clear existing table rows

        applicationsData.forEach((application) => {
            const row = document.createElement('tr');
            
            // Create table cells for each piece of data
            Object.values(application).forEach(text => {
                const cell = document.createElement('td');
                cell.textContent = text;
                row.appendChild(cell);
            });

            // Append the row to the table body
            tableBody.appendChild(row);
        });

        // Show the table
        applicationsTable.style.display = 'table';
    });
});